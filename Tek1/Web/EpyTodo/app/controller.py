from flask import Flask, render_template, redirect, request, make_response
from flask import jsonify, Blueprint, flash, session, Response, url_for
from app import app, INTERNAL_ERROR, TASK_DOES_NOT_EXIST
from app.models import *
import json

def have_error(errors):
    e = json.loads(errors.data.decode("utf-8"))
    if 'error' in e:
        return True
    return False

def catch_error(errors):
    e = json.loads(errors.data.decode("utf-8"))
    if 'error' in e:
        flash(str(e['error']))
        return errors
    return None

def is_not_empty(name):
    if name is None:
        return 0
    if len(name) == 0:
        return 0
    return 1

def validation_register(username, password):
    if is_not_empty(username) == 0 or is_not_empty(password) == 0:
        return jsonify(error=INTERNAL_ERROR)
    if getUserByUsername(username) is not None:
        return jsonify(error="account already exists")
    return jsonify(success="OK!")

def controller_register_index():
    return render_template("register/index.html", title="Register")

def controller_register_create():
    username = request.form.get('username')
    password = request.form.get('password')
    validation = validation_register(username, password)
    if have_error(validation):
        return catch_error(validation)
    store = newUser(username, password)
    if have_error(store):
        return catch_error(store)
    flash("account created")
    return store

def validation_signin(username, password):
    if is_not_empty(username) == 0 or is_not_empty(password) == 0:
        return jsonify(error=INTERNAL_ERROR)
    user = getUserByUsername(username)
    if user is None:
        return jsonify(error="login or password does not match")
    if not check_password_hash(getUserByUsername(username)[3], password):
        return jsonify(error="login or password does not match")
    return jsonify(success="OK!")

def controller_signin_create():
    username = request.form.get('username')
    password = request.form.get('password')
    validation = validation_signin(username, password)
    if have_error(validation):
        return catch_error(validation)
    user = getUserByUsername(username)
    session['user_id'] = user[0]
    flash("signin successful")
    return jsonify(result="signin successful")

def controller_signin_index():
    return render_template("signin/index.html", title="Sign In")

def controller_signout_index():
    session.clear()
    flash("signout successful")
    return jsonify(result="signout successful")

def api_user_index():
    user = getUserById(session.get('user_id'))
    if user is None:
        return make_response(jsonify(error=INTERNAL_ERROR), 500)
    user_to_json = {'user_id': user[0], 'timestamp': user[1], 'username': user[2], 'password': user[3]}
    return jsonify(result=user_to_json)

def controller_profile_index():
    user = getUserById(session.get('user_id'))
    user_to_json = {'user_id': user[0], 'timestamp': user[1], 'username': user[2], 'password': user[3]}
    return render_template("profile/index.html", title="Sign In", user=user_to_json)

def verification_task(task, user_id):
    if task is None:
        return jsonify(error=TASK_DOES_NOT_EXIST)
    if task[5] != user_id:
        return jsonify(error=INTERNAL_ERROR)
    return jsonify(success="OK!")

def api_task_index():
    tasks = getUserTasks(session.get('user_id'))
    tasks_to_json = {"tasks": []}
    if tasks is not None:
        for task in tasks:
            task_master = {task[0]: {"title": task[1], "begin": task[2].strftime("%Y-%m-%d %T"), "end": task[3].strftime("%Y-%m-%d %T"), "status": task[4]}}
            tasks_to_json["tasks"].append(task_master)
    return jsonify(result=tasks_to_json)

def api_task_show(task_id):
    task = getTask(task_id)
    validation = verification_task(task, session.get('user_id'))
    if have_error(validation):
        return catch_error(validation)
    task_to_json = {"title": task[1], "begin": task[2].strftime("%Y-%m-%d %T"), "end": task[3].strftime("%Y-%m-%d %T"), "status": task[4]}
    return jsonify(result=task_to_json)

def api_task_delete(task_id):
    task = getTask(task_id)
    validation = verification_task(task, session.get('user_id'))
    if have_error(validation):
        return catch_error(validation)
    return delTask(task_id)

def verfication_update_task(title, status, begin, end):
    if is_not_empty(title) == 0 or is_not_empty(status) == 0\
            or is_not_empty(begin) == 0 or is_not_empty(end) == 0:
        return jsonify(error=INTERNAL_ERROR)
    if status != 'not started' and status != 'in progress'\
        and status != 'done':
        return jsonify(error=INTERNAL_ERROR)
    return jsonify(success="ok!")

def api_task_update(task_id):
    title = request.form.get('title')
    status = request.form.get('status')
    begin = request.form.get('begin')
    end = request.form.get('end')
    task = getTask(task_id)
    pre_validation = verification_task(task, session.get('user_id'))
    if have_error(pre_validation):
        return catch_error(pre_validation)
    if is_not_empty(begin) == 0:
        begin = "0000-00-00 00:00:00"
    if is_not_empty(end) == 0:
        end = "0000-00-00 00:00:00"
    validation = verfication_update_task(title, status, begin, end)
    if have_error(validation):
        return catch_error(validation)
    return updateTask(task_id, title, status, begin, end)

def api_task_create():
    title = request.form.get('title')
    status = request.form.get('status')
    begin = request.form.get('begin')
    end = request.form.get('end')
    if is_not_empty(begin) == 0:
        begin = "0000-00-00 00:00:00"
    if is_not_empty(end) == 0:
        end = "0000-00-00 00:00:00"
    validation = verfication_update_task(title, status, begin, end)
    if have_error(validation):
        return catch_error(validation)
    return newTask(title, status, begin, end, session.get('user_id'))

from flask import Flask, render_template, flash, jsonify, session
from functools import wraps
from app.controller import *
from app import app

def m_login(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if not session.get('user_id'):
            return jsonify(error="you must be logged in")
        return f(*args, **kwargs)
    return decorated_function

def m_guest(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get('user_id'):
            return jsonify(error=INTERNAL_ERROR)
        return f(*args, **kwargs)
    return decorated_function

@app.route('/', methods=['GET'])
def route_index():
    return render_template("index.html", title="Home")

@app.route('/register', methods=['GET', 'POST'])
@m_guest
def route_register():
    if request.method == 'POST':
        return controller_register_create()
    return controller_register_index()

@app.route('/signin', methods=['GET', 'POST'])
@m_guest
def route_signin():
    if request.method == 'POST':
        return controller_signin_create()
    return controller_signin_index()

@app.route('/signout', methods=['POST'])
@m_login
def route_signout():
    return controller_signout_index()

@app.route('/user', methods=['GET'])
@m_login
def route_api_user():
    return api_user_index()

@app.route('/profile', methods=['GET'])
def route_profile():
    return controller_profile_index()

@app.route('/user/task', methods=['GET'])
@m_login
def route_api_user_task():
    return api_task_index()

@app.route('/user/task/<task_id>', methods=['GET', 'POST'])
@m_login
def route_api_user_task_show(task_id):
    if request.method == 'POST':
        return api_task_update(task_id)
    return api_task_show(task_id)

@app.route('/user/task/add', methods=['POST'])
@m_login
def route_api_user_task_add():
    return api_task_create()

@app.route('/user/task/del/<task_id>', methods=['POST'])
@m_login
def route_api_user_task_delete(task_id):
    return api_task_delete(task_id)
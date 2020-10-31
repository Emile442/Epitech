from config import *
from flask import jsonify, session, flash
import pymysql as sql
from app import app, INTERNAL_ERROR
from werkzeug.security import generate_password_hash, check_password_hash

def connect_database():
	try:
		connect = sql.connect(host=DATABASE_HOST, unix_socket=DATABASE_SOCK,
		user=DATABASE_USER, passwd=DATABASE_PASS, db=DATABASE_NAME)
		return connect
	except Exception:
		return None

def getUserByUsername(username):
	connect = connect_database()
	try:
		cursor = connect.cursor()
		cursor.execute('SELECT * FROM user WHERE username LIKE %s', username)
		result = cursor.fetchone()
		cursor.close()
	except Exception:
		return None
	finally:
		connect.close()
	return result

def getUserById(user_id):
	connect = connect_database()
	try:
		cursor = connect.cursor()
		cursor.execute('SELECT * FROM user WHERE user_id=%s LIMIT 1', user_id)
		result = cursor.fetchone()
		cursor.close()
	except Exception:
		return None
	finally:
		connect.close()
	return result

def newUser(username, password):
	connect = connect_database()
	try:
		hash_password = generate_password_hash(password)
		cursor = connect.cursor()
		cursor.execute('INSERT INTO user (username, password) VALUES (%s, %s)', (username, hash_password))
		connect.commit()
	except Exception:
		return jsonify(error=INTERNAL_ERROR)
	finally:
		connect.close()
	return jsonify(result="account created")

def getUserTasks(user_id):
	connect = connect_database()
	try:
		if connect is None:
			return jsonify(error=INTERNAL_ERROR)
		cursor = connect.cursor()
		cursor.execute('SELECT * FROM task INNER JOIN user_has_task ON task.task_id = user_has_task.fk_task_id WHERE user_has_task.fk_user_id IN (%s)',
					   user_id)
		result = cursor.fetchall()
		cursor.close()
	except Exception:
		return jsonify(error=INTERNAL_ERROR)
	finally:
		connect.close()
	return result

def getTask(task_id):
	connect = connect_database()
	try:
		cursor = connect.cursor()
		cursor.execute(
			'SELECT * FROM task INNER JOIN user_has_task ON task.task_id = user_has_task.fk_task_id WHERE user_has_task.fk_task_id = %s',
			task_id)
		result = cursor.fetchone()
	except Exception:
		return jsonify(error=INTERNAL_ERROR)
	finally:
		connect.close()
	if result is not None:
		return result
	return None

def delTask(task_id):
	connect = connect_database()
	try:
		cursor = connect.cursor()
		cursor.execute('DELETE FROM task WHERE task_id=%s', task_id)
		cursor.execute('DELETE FROM user_has_task WHERE fk_task_id=%s', task_id)
		connect.commit()
	except Exception:
		return jsonify(error=INTERNAL_ERROR)
	finally:
		connect.close()
	return jsonify(result="task deleted")

def updateTask(task_id, title, status, begin, end):
	connect = connect_database()
	try:
		cursor = connect.cursor()
		cursor.execute('UPDATE task SET title=%s, status=%s, begin=%s, end=%s WHERE task_id=%s',
					   (title, status, begin, end, task_id))
		connect.commit()
	except Exception:
		return jsonify(error=INTERNAL_ERROR)
	finally:
		connect.close()
	return jsonify(result="update done")

def getLastTask():
	connect = connect_database()
	try:
		cursor = connect.cursor()
		cursor.execute(
			'SELECT * FROM task ORDER BY task_id DESC LIMIT 1')
		result = cursor.fetchone()
	except Exception:
		return jsonify(error=INTERNAL_ERROR)
	finally:
		connect.close()
	if result is not None:
		return result
	return None

def attachTaskToUser(task_id, user_id):
	connect = connect_database()
	try:
		cursor = connect.cursor()
		cursor.execute('INSERT INTO user_has_task (fk_user_id, fk_task_id) VALUES (%s, %s)', (user_id, task_id))
		connect.commit()
		cursor.close()
	except Exception:
		return jsonify(error=INTERNAL_ERROR)
	finally:
		connect.close()
	return True

def newTask(title, status, begin, end, user_id):
	connect = connect_database()
	try:
		cursor = connect.cursor()
		cursor.execute('INSERT INTO task (title, status, begin, end) VALUES (%s, %s, %s, %s)',
					   (title, status, begin, end))
		connect.commit()
		cursor.close()
		task = getLastTask()
		attachTaskToUser(task[0], user_id)
	except Exception:
		return jsonify(error=INTERNAL_ERROR)
	finally:
		connect.close()
	return jsonify(result="new task added")
from flask import Flask

class Middleware(object):
    def __init__(self, app):
        self.app = app
    def __call__(self, environ, start_response):
         return self.app(environ, start_response)

app = Flask(__name__)
app.config.from_object('config')
app.secret_key = "W9NHB2bx6XR89zL499kz7pVt6uu7TtCz"
app.wsgi_app = Middleware(app.wsgi_app)
INTERNAL_ERROR = 'internal error'
TASK_DOES_NOT_EXIST= 'task id does not exist'

from app import views

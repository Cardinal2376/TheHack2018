import logging
from django.shortcuts import render, redirect, HttpResponse
from django.core.urlresolvers import reverse
from django.conf import settings
from django.contrib.auth import logout, login, authenticate
from django.contrib.auth.hashers import make_password
from django.core.paginator import Paginator, InvalidPage, EmptyPage, PageNotAnInteger
from django.db import connection
from django.db.models import Count

import serial
import threading
import time


def index(request):

    x = serial.Serial('/dev/cu.usbmodem42', 9600)
    id = request.GET.get('id', None)
    print(id)
    myinput = id
    myinput = myinput.encode(encoding="utf-8")
    x.write(myinput)
    return render(request, 'index.html', locals())
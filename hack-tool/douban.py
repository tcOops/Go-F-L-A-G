#!/usr/bin/env python
#encoding: utf-8

import sys, os
import requests
from bs4 import BeautifulSoup
reload(sys)
sys.setdefaultencoding('utf8')
import json, re, time
import threading, Queue

user = None
cookie = {}
xsrf = ""


#Log in Douban By your account
def login():
    global user, cookie

    userEmail = "15821274485"
    userPwd = "345243tc"
    post_data = {'form_email':userEmail, 'form_password':userPwd, 'redir':'https://www.douban.com/subject/22992396/', 'source':'None', 'login':'登录' }

    header = {
        'User-Agent': "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.97 Safari/537.36",
        'Host': "accounts.douban.com",
        'Referer': "https://accounts.douban.com/login"
        }

    s = requests.session()

    url = 'https://accounts.douban.com/login'
    r = s.post(url, data=post_data, headers=header, verify=False)
    user = s
    cookie = r.cookies
    print r.url

class fblbla():
    def __init__(self):
        kind = True

    def get

if __name__ == '__main__':
    login()

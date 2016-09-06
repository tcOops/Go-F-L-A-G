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


#Log in Hihocoder By your account
def login():
    global user, cookie

    userEmail = "geek777@163.com"
    userPwd = "ddos"
    post_data = {'email':userEmail, 'passwd':userPwd}

    header = {
        'User-Agent': "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.97 Safari/537.36",
        'Host': "hihocoder.com",
        'Referer': "http://hihocoder.com/login",
        }

    s = requests.session()

    url = 'http://hihocoder.com/api/User/login.json'
    r = s.post(url, data=post_data, headers=header, verify=False)
    user = s
    cookie = r.cookies
#    print r.json()


class autoSumbiter():
    def __init__(self):
        self.url = "http://hihocoder.com/problemset/problem/"

    def work(self):
        filePath = os.getcwd() + '/hihocoder/hihocoder.cpp'
        haveSubmit = False
        cnt = 0
        while True:
            with open(filePath, 'r') as fn:
                codeSource = fn.readlines()
                if len(codeSource) and ~(codeSource[-1].find('ok')):
                    if cnt < 50:
                        codes = ''.join(codeSource[:-2])
                        pat = re.compile(r'\\n')
                        codes = pat.sub(r'\\r\\n', codes)
                        proNo = codeSource[-2]
                        global user, cookie
                        if user is None:
                            login()

                        contestId = str(0)
                        problemId = proNo[:-1]
                        lang = 'G++'
                        post_data = {'contest-id':contestId, 'problem-id':problemId, 'source':codes, 'language': lang}
                        #print post_data
                        header = {
                            'User-Agent': "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.97 Safari/537.36",
                            'Host': "hihocoder.com",
                            'Referer': "http://hihocoder.com/problemset",
                        }

                        s = user
                        url = 'http://hihocoder.com/api/problem/submit.json'
                        r = s.post(url, data=post_data, headers=header, verify=False, cookies = cookie)
                        print r.json()
                        haveSubmit = True
                        cnt += 1
                        time.sleep(1)
                else:
                    haveSubmit = False


if __name__ == '__main__':
    autoer = autoSumbiter()
    autoer.work()

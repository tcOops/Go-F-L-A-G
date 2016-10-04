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
homeUrl = "http://hihocoder.com"
urlVisit = []
archive = {}
taskPool, noPool = Queue.Queue(maxsize = -1), Queue.Queue(maxsize = -1)
ACNumber, workers = 0, 5


#Log in Hihocoder By your account
def login():
    global user, cookie

    userEmail = "345243921@qq.com"
    userPwd = "345243tc"
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


#Init the parament
def init():
    global urlVisit, user, archive
    urlVisit = []
    if user is None:
        login()

    url = "http://hihocoder.com/problemset"
    s = user
    r = s.get(url, cookies = cookie)
    pat = re.compile(r'/problemset/problem/(\d+)')
    problemIds = pat.findall(r.content)
    problemIds = [problemIds[i] for i in xrange(len(problemIds)) if i & 1]

    pat = re.compile(r'href="/problemset/problem/\d+">(.+)</a></div>')
    problemNames = pat.findall(r.content)
    archive = dict(zip(problemIds, problemNames))

    archivePath = os.getcwd() + "/archive"
    if not os.path.exists(archivePath):
        os.makedirs(archivePath)

#Get all my submissions which is accept
class get_AC_train():
    global user, cookie, homeUrl, num
    def __init__(self):
        self.url = "http://hihocoder.com/problemset/submitted"
        if user is None:
            login()

    def parse(self):
        global ACNumber, taskPool
        s = user
        r = s.get(self.url, cookies = cookie)
        pat = re.compile(r'(/problemset/submitted\?page=\d+)')
        pageLinks = pat.findall(r.content)
      #  urlVisit = []

        for pageLink in pageLinks[::-1]:
            print pageLink
            if pageLink in urlVisit:
                continue
            urlVisit.append(pageLink)
            fetch = fetcher_train(homeUrl + pageLink);
            fetch.start()


        for worker in xrange(workers):
            roboter = robot()
            roboter.start()


#Fetch all train code-links
class fetcher_train(threading.Thread):
    global user, cookie, homeUrl
    def __init__(self, index):
        threading.Thread.__init__(self)
        self.index = index

    def run(self):
        global ACNumber, taskPool, noPool
        s = requests.session()
        r = s.get(self.index, cookies = cookie)
        pat = re.compile(r'(/problemset/solution/\d+)')
        ACLinks = pat.findall(r.content)
        pat = re.compile(r'(AC|TLE|WA|CE|PE|RE)')
        status = pat.findall(r.content)
        pat = re.compile(r'<td>(\d+)</td>')
        numbers = pat.findall(r.content)

#        ACNumber = ACNumber + len([ACLinks[i] for i in xrange(len(ACLinks)) if status[i] == 'AC'])
        for idx in xrange(len(ACLinks)):
            if status[idx+1] == 'AC':
                ACNumber = ACNumber + 1
                taskPool.put(homeUrl + ACLinks[idx])
                noPool.put(numbers[idx])


#Fetch all sourceCodes and data persistence
class robot(threading.Thread):
    global cookie
    def __init__(self):
        threading.Thread.__init__(self)

    def run(self):
        while True:
            task = taskPool.get(block = True)
            print task
            no = noPool.get(block = True)
            s = requests.session()
            r = s.get(task, cookies = cookie)

            pat = re.compile(r'setValue\("(.*)"\);')
            source = pat.findall(r.content)
            archivePath = os.getcwd() + "/archive"

            for s in source:
                s = s.decode('unicode_escape')
                pat = re.compile(r'\\r\\n')
                s = pat.sub(r'\n', s)
                pat = re.compile(r'\\(?!n)')
                s = pat.sub(r'', s)
                fileName = archivePath + '/' + str(no) + '.cpp'
                with open(fileName, 'w') as fn:
                    fn.write(s)


#Get all my submissions which is accepted in contest
class get_AC_contest():
    global user, cookie, homeUrl, num
    def __init__(self):
        self.url = "http://hihocoder.com/contests/past"
        if user is None:
            login()

    def parse(self):
        global ACNumber, taskPool

        s = user
        r = s.get(self.url, cookies = cookie)
        pat = re.compile(r'md-summary-cnt">[\n\s]+<a href=".+">(.+)</a>')
        contests = pat.findall(r.content)
        pat = re.compile(r'md-summary-cnt">[\n\s]+<a href="(.+)">.+</a>')
        contestLinks = pat.findall(r.content)
        pat = re.compile(r'md-summary-side-action">(.+)</a>')
        status = pat.findall(r.content)

        joinContests = dict(zip(contests, status))
        contestLinks = dict(zip(contests, contestLinks))

        for contest in joinContests:
            if joinContests[contest] == '已经报名':
                submitPageLink = 'http://hihocoder.com' + contestLinks[contest] + '/submitted'
                r = s.get(submitPageLink, cookies = cookie)
                pat = re.compile(r'(AC|TLE|WA|CE|PE|RE)')
                status = pat.findall(r.content)
                pat = re.compile(r'op"><a href="(.+)">')
                sourceLinks = pat.findall(r.content)
                pat = re.compile(r'<td>(.+)</td>[\n\s]+<td class="fn-color-red')
                proNames = pat.findall(r.content)

                for idx in xrange(len(sourceLinks)):
                    if status[idx+1] == 'AC':
                        contest_AC_codes_persistence(contest, proNames[idx], sourceLinks[idx])


def contest_AC_codes_persistence(contestName, proName, sourceLinks):
    global archive, homeUrl
#    print contestName, proName, sourceLinks
    s = requests.session()
    r = s.get(homeUrl + sourceLinks, cookies = cookie)

    pat = re.compile(r'setValue\("(.*)"\);')
    source = pat.findall(r.content)
    contestPath = os.getcwd() + "/contest/" + contestName

    if not os.path.exists(contestPath):
        os.makedirs(contestPath)
    for s in source:
        s = s.decode('unicode_escape')
        pat = re.compile(r'\\r\\n')
        s = pat.sub(r'\n', s)
        pat = re.compile(r'\\t')
        s = pat.sub(r' ', s)
        pat = re.compile(r'\\(?!n)')
        s = pat.sub(r'', s)
        fileName = contestPath + '/' + proName + '.cpp'
        with open(fileName, 'w') as fn:
            fn.write(s)

        for key in archive:
            if archive[key] == proName:
                print proName
                taskPool.put(homeUrl + sourceLinks)
                noPool.put(key)
                break

#Get all my submissions which is accepted in hiho
class get_AC_hiho():
    global user, cookie, homeUrl, num
    def __init__(self):
        self.url = "http://hihocoder.com/hiho/past"
        if user is None:
            login()

    def parse(self):
        global ACNumber, taskPool

        s = user
        r = s.get(self.url, cookies = cookie)
        pat = re.compile(r'md-summary-cnt">[\n\s]+<a href=".+">(.+)</a>')
        contests = pat.findall(r.content)
        pat = re.compile(r'md-summary-cnt">[\n\s]+<a href="(.+)">.+</a>')
        contestLinks = pat.findall(r.content)
        pat = re.compile(r'md-summary-side-action">(.+)</a>')
        status = pat.findall(r.content)

        joinContests = dict(zip(contests, status))
        contestLinks = dict(zip(contests, contestLinks))

        for contest in joinContests:
            if joinContests[contest] == '已经报名':
                submitPageLink = 'http://hihocoder.com' + contestLinks[contest] + '/submitted'
                r = s.get(submitPageLink, cookies = cookie)
                pat = re.compile(r'(AC|TLE|WA|CE|PE|RE)')
                status = pat.findall(r.content)
                pat = re.compile(r'op"><a href="(.+)">')
                sourceLinks = pat.findall(r.content)
                pat = re.compile(r'<td>(.+)</td>[\n\s]+<td class="fn-color-red')
                proNames = pat.findall(r.content)

                for idx in xrange(len(sourceLinks)):
                    if status[idx+1] == 'AC':
                        hiho_AC_codes_persistence(contest, proNames[idx], sourceLinks[idx])


def hiho_AC_codes_persistence(contestName, proName, sourceLinks):
    global archive, homeUrl
#    print contestName, proName, sourceLinks
    s = requests.session()
    r = s.get(homeUrl + sourceLinks, cookies = cookie)

    pat = re.compile(r'setValue\("(.*)"\);')
    source = pat.findall(r.content)

    hihoPath = os.getcwd() + "/hiho/" + contestName
    if not os.path.exists(hihoPath):
        os.makedirs(hihoPath)
    for s in source:
        s = s.decode('unicode_escape')
        pat = re.compile(r'\\r\\n')
        s = pat.sub(r'\n', s)
        pat = re.compile(r'\\(?!n)')
        s = pat.sub(r'', s)
        fileName = hihoPath + '/' + proName + '.cpp'
        with open(fileName, 'w') as fn:
            fn.write(s)

        for key in archive:
            if archive[key] == proName:
                print proName
                taskPool.put(homeUrl + sourceLinks)
                noPool.put(key)
                break


if __name__ == '__main__':
    init()
    ac_train = get_AC_train()
    ac_contest = get_AC_contest()
    ac_hiho = get_AC_hiho()
    ac_train.parse()
    ac_contest.parse()
    ac_hiho.parse()

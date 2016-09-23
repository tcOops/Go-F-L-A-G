//AC
// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <ctime>
//#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1000000007;

ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

inline void gn(long long &x){
    int sg=1;
    char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}

inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}

const int N = 100010;
map<string, int > mp;
int in[N];
vector<int > g[N];
bool vis[N];
string word;
queue<int > que;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int T, n, cases = 1;
  gn(T);
  while(T--) {
    gn(n);
    int cnt = 0;
    mp.clear();
    memset(in, 0, sizeof(in));
    memset(vis, false, sizeof(vis));

    for(int i = 0; i < n; ++i) {
      cin >> word;
      string w1 = "";
      int idx = 0;
      while(word[idx] != '=') {
        w1 += word[idx++];
      }
      ++idx;
      while(word[idx++] != '(') {
      }
      if(mp.find(w1) == mp.end()) {
        mp[w1] = cnt++;
        g[mp[w1]].clear();
      }
  //    cout << w1 << endl;
      vis[mp[w1]] = true;
      string res;
      for(; word[idx] != ')';) {
        int k = idx;
        res = "";
        while(word[k] != ')' && word[k] != ',') {
          res += word[k++];
        }
      //  cout << res << endl;
        if(mp.find(res) == mp.end()) {
          mp[res] = cnt++;
          g[mp[res]].clear();
        }
        g[mp[res]].push_back(mp[w1]);
        in[mp[w1]]++;
        idx = k;
        if(word[idx] == ',') {
          ++idx;
        }
      }
    }

    while(!que.empty()) {
      que.pop();
    }
    for(int i = 0; i < cnt; ++i) {
      if(in[i] == 0 && vis[i]) {
        que.push(i);
      }
    }

    int num = 0;
    while(!que.empty()) {
      ++num;
      int p = que.front();
      que.pop();
      for(auto v : g[p]) {
        if(p == v) {
          continue;
        }
        in[v]--;
        if(in[v] == 0) {
          que.push(v);
        }
      }
    }


    if(num == cnt) {
      printf("Case #%d: GOOD\n", cases++);
    }
    else {
      printf("Case #%d: BAD\n", cases++);
    }
  }
  return 0;
}

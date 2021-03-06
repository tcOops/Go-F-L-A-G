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
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll MOD = 1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
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

const int N = 200010;
set<int > g[N];
queue<int > que;
set<int > keep, del;
int dist[N];
int n, m, s;

void solve(int s) {
  while(!que.empty()) {
    que.pop();
  }
  que.push(s);
  keep.clear();
  for(int i = 1; i <= n; ++i) {
    if(i != s) {
      keep.insert(i);
    }
  }

  dist[s] = 0;
  while(!que.empty()) {
    int p = que.front();
    que.pop();
    del.clear();
    for(set<int >::iterator it = keep.begin(); it != keep.end(); ++it) {
      if(g[p].find(*it) == g[p].end()) {
        que.push(*it);
        del.insert(*it);
        dist[*it] = dist[p] + 1;
      }
    }
    for(set<int >::iterator it = del.begin(); it != del.end(); ++it) {
      keep.erase(*it);
    }
  }
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int T; scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for(int i = 0; i < m; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      g[x].insert(y);
      g[y].insert(x);
    }
    memset(dist, -1, sizeof(dist));
    scanf("%d", &s);
    solve(s);
    for(int i = 1; i <= n; ++i) {
      if(i != s) {
        printf("%s%d", (i != 2 && s == 1) || (s != 1 && i != 1) ? " " : "", dist[i]);
      }
    }
    puts("");
  }
  return 0;
}

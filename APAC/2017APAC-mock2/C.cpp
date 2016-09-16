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
#include <bitset>
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

vector<pair<int, int > > cache;
bool vis[10];
int by[10][10];

int n, ans = 0;

void pre() {
  memset(by, 0, sizeof(by));
  by[1][3] = by[3][1] = 2;
  by[1][7] = by[7][1] = 4;
  by[1][9] = by[9][1] = 5;
  by[2][8] = by[8][2] = 5;
  by[3][9] = by[9][3] = 6;
  by[3][7] = by[7][3] = 5;
  by[4][6] = by[6][4] = 5;
  by[7][9] = by[9][7 ] = 8;
}

void dfs(int u, int cnt, int sta) {
  if(cnt >= 4 && sta == (1<<n) - 1) {
    ++ans;
  //  cout << ans << " " << sta << endl;
  }

  for(int i = 1; i <= 9; ++i) {
    if(i == u || vis[i]) continue;
    if(by[u][i] == 0 || (by[u][i] != 0 && vis[by[u][i]])) {
      int cpy = sta;
      for(int j = 0; j < n; ++j) {
        if(cache[j].first == u && cache[j].second == i || (cache[j].first == i && cache[j].second == u)) {
          sta = sta | (1<<j);
        }
      }
      vis[i] = true;
      dfs(i, cnt + 1, sta);
      sta = cpy;
      vis[i] = false;
    }
  }

}

int main() {
  int T; gn(T);
  pre();
  while(T--) {
    gn(n);
    cache.clear();
    for(int i = 0; i < n; ++i) {
      int x, y;
      gn(x); gn(y);
      cache.push_back(make_pair(x, y));
    }

    ans = 0;
    for(int i = 1; i <= 9; ++i) {
      memset(vis, false, sizeof(vis));
      vis[i] = true;
      dfs(i, 1, 0);
    }
    cout << ans << endl;
  }
  return 0;
}

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

const int N = 110;
vector<int> g[N];
bitset<N > f[N];
bool used[N][N];
int a[N], n, m, idx;
bool suc;

void pre(int u, int fa) {
  f[u][u] = 1;
  for(auto v : g[u]) {
    if(v == fa) continue;
    pre(v, u);
    f[u] |= f[v];
  }
}

void solve(int u, int fa) {
  if(idx < m && a[idx] == u) {
    ++idx;
  }
  if(idx == m) {
    suc = true;
    return ;
  }

  while(idx < m) {
    int res = idx;
    int need = a[idx];
    for(auto v : g[u]) {              
      if(v == fa) continue;
      if(f[v][need] && !used[u][v]) {
        used[u][v] = true;
        solve(v, u);
        break;
      }
    }
    if(res == idx) {
      break;
    }
  }
}

int main() {
  int T; gn(T);
  while(T--) {
    gn(n);
    memset(used, true, sizeof(used));
    suc = false;
    for (int i = 1 ; i <= n ; i ++) {
          g[i].clear();
          f[i].reset();
    }
    for(int i = 1; i < n; ++i) {
      int x, y;
      gn(x); gn(y);
      used[x][y] = used[y][x] = false;
      g[x].push_back(y), g[y].push_back(x);
    }
    gn(m);
    for(int i = 0; i < m; ++i) {
      gn(a[i]);
    }
    pre(1, 0);

    idx = 0;
    solve(1, 0);
    if(suc) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

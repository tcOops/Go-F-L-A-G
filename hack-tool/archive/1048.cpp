//AC

// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//
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

const int N = 1010;
long long tran[35][35];
int n, m;

void dfs(int cur, long long sta1, long long sta2) {
  if(cur == m) {
    tran[sta1][sta2] = 1;
    return ;
  }
  dfs(cur + 1, sta1<<1, sta2<<1|1);
  dfs(cur + 1, sta1<<1|1, sta2<<1);
  if(cur + 2 <= m) {
    dfs(cur + 2, (sta1<<2)+3, (sta2<<2)+3);
  }
}

void cal(long long a[][35], long long b[][35], int n) {
  long long c[35][35];
  memset(c, 0, sizeof(c));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      for(int k = 0; k < n; ++k) {
        c[j][k] = a[j][i]*b[i][k]%MOD + c[j][k];
        c[j][k] %= MOD;
       }
    }
  }

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      a[i][j] = c[i][j];
    }
  }
}

void fastMul(long long a[][35], int k) {
  long long c[35][35];
  memset(c, 0, sizeof(c));
  for(int i = 0; i < 35; ++i) {
    c[i][i] = 1;
  }

  while(k) {
    if(k & 1) {
      cal(c, a, (1<<m));
    }
    k >>= 1;
    cal(a, a, (1<<m));
  }

  for(int i = 0; i < (1<<m); ++i) {
    for(int j = 0; j < (1<<m); ++j) {
      a[i][j] = c[i][j];
    }
  }
}

void solve() {
  memset(tran, 0, sizeof(tran));
  dfs(0, 0, 0);
  fastMul(tran, n);
  long long ans = tran[(1<<m)-1][(1<<m)-1];
  cout << ans << endl;
}

int main() {
  gn(n); gn(m);
  solve();
  return 0;
}

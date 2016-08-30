

// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

// Codeforces 365
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

const int N = 110;
const ll INF = 0x3f3f3f3f3f;
long long dp[N][N][N];
int col[N][N];
int c[N];

int main() {
  int n, m, k;
  gn(n); gn(m); gn(k);
  for(int i = 1; i <= n; ++i) {
    gn(c[i]);
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      gn(col[i][j]);
    }
  }
  memset(dp, INF, sizeof(dp));
  if(c[1] == 0) {
    for(int i = 1; i <= m; ++i) {
      dp[1][1][i] = col[1][i];
    }
  }
  else {
    dp[1][1][c[1]] = 0;
  }

  for(int i = 2; i <= n; ++i) {
    for(int j = 1; j <= k; ++j) {
      if(c[i] == 0) {
        for(int a = 1; a <= m; ++a) {
          dp[i][j][a] = min(dp[i][j][a], dp[i-1][j][a] +col[i][a]);
          for(int p = 1; p <= m; ++p) {
            if(p == a) continue;
            dp[i][j][a] = min(dp[i][j][a], dp[i-1][j-1][p] + col[i][a]);
          }
        }
      }
      else {
        dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j][c[i]]);
        for(int a = 1; a <= m; ++a) {
          if(a != c[i]) {
            dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j-1][a]);
          }
        }
      }
    }
  }

  long long ans = INF;
  for(int i = 1; i <= m; ++i) {
    if(dp[n][k][i] < ans) {
      ans = dp[n][k][i];
    }
  }
  if(ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}

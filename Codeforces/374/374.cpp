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
const ll MOD = 1000000007;

ll powMOD(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
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

const int N = 1050;
int dp[N][N];
int tmp[N];
vector<int > g[N];
int val[N];
int n, m;

void solve(int u, int fa) {
  dp[u][val[u]] = 1;
  for(auto v : g[u]) {
    if(v == fa) continue;
    solve(v, u);
    for(int i = 0; i < m; ++i) {
      tmp[i] = dp[u][i];
    }
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < m; ++j) {
        dp[u][i] = (dp[v][j]*tmp[i^j]%MOD + dp[u][i])%MOD;
      }
    }
  }
}
 ？
int main() {
  int T; gn(T);
  while(T--) {
    gn(n); gn(m);
    for(int i = 1; i <= n; ++i) {
      gn(val[i]);
      g[i].clear();
    }
    for(int i = 1; i < m; ++i) {
      int x, y;
      gn(x); gn(y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    memset(dp, 0, sizeof(dp));
    solve(1, -1);

    for(int i = 0; i < m; ++i) {
      int ans = 0;
      for(int j = 1; j <= n; ++j) {
        ans = (ans + dp[j][i])%MOD;
      }
      if(i) {
        printf(" ");
      }
      printf("%d", ans);
    }
    cout << endl;
  }
  return 0;
}

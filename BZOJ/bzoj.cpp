//AC

// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

// BZOJ 2839
// 经典容斥原理

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

<<<<<<< HEAD
const int N = 51;
const int INF = 0x3f3f3f3f;
int dp[N][N];
int a[N], sum[N];

int main() {
  int n; gn(n);
  sum[0] = 0;
  for(int i = 1; i <= n; ++i) {
    gn(a[i]);
    sum[i] = sum[i-1] + a[i];
  }

  memset(dp, INF, sizeof(dp));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= i; ++j) {
      dp[i][j] = 0;
    }
  }
  if(n >= 2) {
    for(int i = 1; i < n; ++i) {
      dp[i][i+1] = (a[i] == a[i+1] ? 0 : 1);
    }
  }

  for(int t = 3; t <= n; ++t) {
    for(int i = 1; i+t-1 <= n; ++i) {
      int j = i + t - 1;
      bool flag = false;
      for(int k = i; k <= j; ++k) {
        for(int p = k + 1; p <= j; ++p) {
          if(sum[k] - sum[i-1] == sum[j] - sum[p-1]) {
            flag = true;
            if(dp[k+1][p-1] + (k - i) + (j - p) < dp[i][j]) {
              dp[i][j] = dp[k+1][p-1] + (k - i) + (j - p);
            }
          }
        }
      }
      if(!flag) {
        dp[i][j] = j - i;
      }
    }
  }
  cout << dp[1][n] << endl;
=======
int dp[1000][2];

int solve(int n, int m) {
  if(n == 0) return 0;
  if(m == 1) return n;
  if(dp[n][m] != -1) {
    return dp[n][m];
  }

  int ans = 1e9;
  for(int i = 1; i <= n; ++i) {
    int tmp = max(solve(i-1, m-1), solve(n-i, m)) + 1;
    if(tmp < ans) {
      ans = tmp;
    }
  }
  return dp[n][m] = ans;
}

int main() {
  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(200, 2));
>>>>>>> 0da26a6ccabb0207ba964b8bd89b7bc9efead390
  return 0;
}

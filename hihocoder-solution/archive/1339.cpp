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

const int N = 110;
const int M = 610;
double dp[N][M];

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  memset(dp, 0, sizeof(dp));

  double res = pow(6.0, n/2);
  dp[0][0] = 100.0/res;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      for(int k = 1; k <= 6; ++k) {
        if(j < k) continue;
        dp[i][j] += dp[i-1][j-k];
      }
    }
  }

  double ans = dp[n][m]/pow(6.0, n-n/2);
  printf("%.2lf\n", ans);
  return 0;
}

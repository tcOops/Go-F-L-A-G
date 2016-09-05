//AC
// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//POJ 1160
//简单DP, 考虑到最优情况一定是一个邮局覆盖一片连续区域， 每个邮局之间互不干扰。
//对于一个邮局而言，就是取中点最优啦。 这样就转化为一个简单的区间DP

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

const int N = 31;
const int INF = 0x3f3f3f3f;
int dp[N][N];
int d[N], cost[N][N];

int main() {
  int p, v;
  gn(p); gn(v);
  for(int i = 1; i <= p; ++i) {
    gn(d[i]);
  }
  for(int i = 1; i <= p; ++i) {
    for(int j = i; j <= p; ++j) {
      int dist = 0;
      for(int k = i; k <= j; ++k) {
        dist += abs(d[k] - d[(i+j)/2]);
      }
      cost[i][j] = dist;
    }
  }

  memset(dp, INF, sizeof(dp));
  dp[0][0] = 0;
  for(int i = 1; i <= p; ++i) {
    for(int j = 1; j <= v; ++j) {
      for(int k = 0; k < i; ++k) {
        dp[i][j] = min(dp[i][j], dp[k][j-1] + cost[k+1][i]);
      }
    }
  }
  cout << dp[p][v];
  return 0;
}

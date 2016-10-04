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

const int N = 1010;
int a[N], dp[N][N], sum[N];

int solve(int l, int r) {
  if(l == r) {
    return a[l];
  }

  if(dp[l][r] != -MOD) {
    return dp[l][r];
  }

  int ans = a[l] + sum[r] - sum[l] - solve(l+1, r);
  int res = a[r] + sum[r-1] - sum[l-1] - solve(l, r-1);
  if(res > ans) {
    ans = res;
  }

  return (dp[l][r] = ans);
}

int main() {
  int n; gn(n);
  sum[0] = 0;
  //memset(dp, -1, sizeof(dp));

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      dp[i][j] = -MOD;
    }
  }
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum[i] = sum[i-1] + a[i];
  }

  int ans = solve(1, n);
  cout << ans << endl;
  return 0;
}

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

const int N = 3010;
const int INF = 0x7f;
int a[N], b[N];
long long dp[N][N];
long long small[N];

int main() {
  int n;
  gn(n);
  for(int i = 1; i <= n; ++i) {
    gn(a[i]);
    a[i] -= i;
    b[i] = a[i];
  }

  sort(b+1, b+n+1);
  int cnt = 2;
  for(int i = 2; i <= n; ++i) {
    if(b[i] != b[cnt-1]) {
      b[cnt++] = b[i];
    }
  }

  memset(dp, INF, sizeof(dp));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j < cnt; ++j) {
      dp[i][j] = min(dp[i][j], small[j] + abs(a[i] - b[j]));
    }
    small[1] = dp[i][1];
    for(int j = 2; j < cnt; ++j) {
      small[j] = min(small[j-1], dp[i][j]);
    }
  }

  long long ans = dp[n][1];
  for(int i = 2; i < cnt; ++i) {
    if(dp[n][i] < ans) {
      ans = dp[n][i];
    }
  }
  cout << ans << endl;
  return 0;
}

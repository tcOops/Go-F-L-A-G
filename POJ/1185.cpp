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
int dp[N][70][70];
int ok = 0, sta[70];
int hill[N];
int n, m;
char maze[N][11];

bool judge(int sta) {
  if(sta & (sta << 1)) {
    return false;
  }
  if(sta & (sta << 2)) {
    return false;
  }
  return true;
}

void gen(int m) {
  ok = 0;
  for(int i = 0; i < (1<<m); ++i) {
    if(judge(i)) {
      sta[ok++] = i;
    }
  }
}

bool fit(int sta, int k) {
  if(sta & (hill[k])) {
    return false;
  }
  return true;
}

int sum(int x) {
  int ret = 0;
  for(; x > 0; x = x&(x-1), ++ret);
  return ret;
}

int main() {
  gn(n); gn(m);
  gen(m);

  for(int i = 0; i < n; ++i) {
    scanf("%s", maze[i]);
    for(int j = 0; j < m; ++j) {
      if(maze[i][j] == 'H') {
        hill[i] |= 1 << (m-1-j);
      }
    }
  }

  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < ok; ++i) {
    if(fit(sta[i], 0)) {
      dp[0][0][i] = sum(sta[i]);
    }
  }

  for(int i = 1; i < n; ++i) {
    for(int j = 0; j < ok; ++j) {
      if(!fit(sta[j], i)) continue;
      for(int k = 0; k < ok; ++k) {
        if(sta[k] & sta[j]) continue;
        for(int t = 0; t < ok; ++t) {
          if(sta[t] & sta[j]) continue;
          if(dp[i-1][t][k] == -1) continue;
          dp[i][k][j] = max(dp[i][k][j], dp[i-1][t][k] + sum(sta[j]));
        }
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < ok; ++i) {
    for(int j = 0; j < ok; ++j) {
      if(dp[n-1][i][j] > ans) {
        ans = dp[n-1][i][j];
      }
    }
  }
  cout << ans << endl;
  return 0;
}

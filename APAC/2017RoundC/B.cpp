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

const int N = 3010;
bool maze[N][N];
int dp[N][N];

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T; gn(T);
  int cases = 1;
  while(T--) {
    int m, n, k;
    gn(m); gn(n); gn(k);
    memset(maze, true, sizeof(maze));
    for(int i = 0; i < k; ++i) {
      int x, y;
      gn(x); gn(y);
      maze[x][y] = false;
    }
    memset(dp, 0, sizeof(dp));

    long long ans = 0;
    for(int i = 0; i < n; ++i) {
      if(maze[0][i]) {
        dp[0][i] = 1;
        ++ans;
      }
    }
    for(int i = 1; i < m; ++i) {
      if(maze[i][0]) {
        dp[i][0] = 1;
        ++ans;
      }
    }

    for(int i = 1; i < m; ++i) {
      for(int j = 1; j < n; ++j) {
        if(maze[i][j]) {
          dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        }
        ans += dp[i][j];
      }
    }
    printf("Case #%d: %lld\n", cases++, ans);
  }
  return 0;
}

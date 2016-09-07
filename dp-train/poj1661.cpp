//AC
// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//POJ 1661
//经典DP题，　有几个地方需要注意：
//注意分开考虑当前平台左右两个方向是否能直接跳下
//注意两个边界需要取到

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

const int N = 1010;
const int INF = 0x3f3f3f3f;
int dp[N][2];
int shadow[N][2];

struct platform {
  int l, r, h;
  bool operator <(const platform &rhs) const {
    return h > rhs.h;
  }
} p[N];

int main() {
  int T; gn(T);
  while(T--) {
    int n, x, y, h, lim;
    gn(n); gn(p[0].l); gn(p[0].h); gn(lim);
    p[0].r = p[0].l;

    int cnt = 1;
    for(int i = 1; i <= n; ++i) {
      gn(x); gn(y); gn(h);
      if(h < p[0].h) {
        p[cnt].l = x; p[cnt].r = y; p[cnt++].h = h;
      }
    }
    sort(p, p + cnt);

    memset(dp, INF, sizeof(dp));
    memset(shadow, -1, sizeof(shadow));
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i < cnt; ++i) {
      for(int j = 0; j < i; ++j) {
        if((p[j].l >= p[i].l && p[j].l <= p[i].r) && !~shadow[j][0]) {
          shadow[j][0] = i;
          if(p[j].h - p[i].h <= lim) {
            dp[i][0] = min(dp[i][0], dp[j][0] + p[j].h - p[i].h + p[j].l - p[i].l);
            dp[i][1] = min(dp[i][1], dp[j][0] + p[j].h - p[i].h + p[i].r - p[j].l);
          }
        }
        if((p[j].r >= p[i].l && p[j].r <= p[i].r) && !~shadow[j][1]) {
          shadow[j][1] = i;
          if(p[j].h - p[i].h <= lim) {
            dp[i][0] = min(dp[i][0], dp[j][1] + p[j].h - p[i].h + p[j].r - p[i].l);
            dp[i][1] = min(dp[i][1], dp[j][1] + p[j].h - p[i].h + p[i].r - p[j].r);
          }
        }
      }
    }

    int ans = INF;
    for(int i = cnt - 1; i >= 0 && p[i].h <= lim; --i) {
      if(dp[i][0] + p[i].h < ans && !~shadow[i][0]) {
        ans = dp[i][0] + p[i].h;
      }
      if(dp[i][1] + p[i].h < ans && !~shadow[i][1]) {
        ans = dp[i][1] + p[i].h;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

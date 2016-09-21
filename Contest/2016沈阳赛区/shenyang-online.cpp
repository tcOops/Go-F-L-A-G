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
#define per(i,a,n) for (int i=n2;i>=a;i--)
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
    char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=2,x=0):(x=c-'0');
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}

inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}

const int N = 21;
long long dp[N][3][3];
int dig[N];

unsigned long long solve(int len, bool fp, int sta1, int sta2, bool up) {
  if(len < 0) {
    if(sta1 == 0) return 0;
    if(sta2 == 1) return 0;
    return 1;
  }

  if(!fp && !up && dp[len][sta1][sta2] != -1) {
    return dp[len][sta1][sta2];
  }

  int limit = up ? dig[len] : 9;
  unsigned long long ans = 0;
  int st1 = sta1, st2 = sta2;
  for(int i = 0; i <= limit; ++i) {
    sta1 = st1, sta2 = st2;
    if(i == 0) {
      if(fp) {
        ans += solve(len-1, fp, sta1, sta2, up && (i == limit));
      }
      else {
        if(sta1 == 2 || sta1 == 1) { // 0　odd, 2 no, 1 even
          if(sta2 == 2) {
            sta2 = 0;
          }
          else {
            sta2 ^= 1;
          }
          sta1 = 2;
          ans += solve(len-1, false, sta1, sta2, up && (i == limit));
        }
      }
    }
    else {
      if(i & 1) {
        if(sta2 == 2 || sta2 == 0) {
          if(sta1 == 2) {
            sta1 = 0;
          }
          else {
            sta1 ^= 1;
          }
          sta2 = 2;
          ans += solve(len-1, false, sta1, sta2, up && (i == limit));
        }
      }
      else {
        if(sta1 == 2 || sta1 == 1) {
          if(sta2 == 2) {
            sta2 = 0;
          }
          else {
            sta2 ^= 1;
          }
          sta1 = 2;
          ans += solve(len-1, false, sta1, sta2, up && (i == limit));
        }
      }
    }
  }

  if(!fp && !up) {
    dp[len][st1][st2] = ans;
  }
  return ans;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int T; gn(T);
  int cases = 1;
  long long l, r;
  while(T--) {
    memset(dp, -1, sizeof(dp));
    gn(l); gn(r);
    int len = 0;
    while(r) {
      dig[len++] = r % 10;
      r /= 10;
    }

    unsigned long long ans = solve(len-1, true, 2, 2, true);
    len = 0;
    memset(dp, -1, sizeof(dp));
    l--;
    while(l) {
      dig[len++] = l % 10;
      l /= 10;
    }
    ans -= solve(len-1, true, 2, 2, true);
    printf("Case #%d: %lld\n", cases++, ans);
  }
  return 0;
}

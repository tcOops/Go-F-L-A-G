// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2_017/5/15」

//Google mock-contest 1
//RejudgeX: 2_016/8/3 22:35 - 24:00
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

const int N = 1e5 + 10;
int good[11][11];
int dp[N];
int n, m;

void _01Bag(int x, int y) {
  for(int i = m; i >= x; --i) {
    dp[i] = max(dp[i], dp[i-x] + y);
  }
}

void fullBag(int x, int y) {
  for(int i = m; i <= x; ++i) {
    dp[i] = max(dp[i], dp[i-x] + y);
  }
}

void multiBag(int x, int y, int z) {
  if(x*z >= m) {
    fullBag(x, y);
  }
  else {
    int base = 1;
    while(base < z) {
      _01Bag(x*base, y*base);
      z -= base;
      base <<= 1;
    }
    _01Bag(x*z, y*z);
  }
}

int main() {
  gn(n); gn(m);

  for(int i = 1; i <= n; ++i) {
    int x, y;
    gn(x); gn(y);
    good[x][y]++;
  }

  for(int i = 1; i <= 10; ++i) {
    for(int j = 1; j <= 10; ++j) {
      if(good[i][j]) {
        multiBag(i, j, good[i][j]);
      }
    }
  }
  cout << dp[m] << endl;
  return 0;
}

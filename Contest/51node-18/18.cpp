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
#include <bitset>
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

long long mat[4][4] = {
  {1, 0, 1, 0},
  {1, 0, 1, 0},
  {0, 0, 0, 1},
  {0, 1, 0, 1}
};

void cal(long long a[][4], long long b[][4], int mod) {
  long long c[4][4];
  memset(c, 0, sizeof(c));
  for(int i = 0; i < 4; ++i) {
    for(int j = 0; j < 4; ++j) {
      for(int k = 0; k < 4; ++k) {
        c[i][j] = (c[i][j] + a[i][k] * b[k][j] % mod) % mod;
      }
    }
  }

  for(int i = 0; i < 4; ++i) {
    for(int j = 0; j < 4; ++j) {
      a[i][j] = c[i][j];
    }
  }
}

void solve(long long a[][4], long long k, int mod) {
  long long c[4][4];
  memset(c, 0, sizeof(c));
  for(int i = 0; i < 4; ++i) {
    c[i][i] = 1;
  }

  while(k) {
    if(k & 1) {
      cal(c, a, mod);
    }
    k >>= 1;
    cal(a, a, mod);
  }

  long long ans = 0;
  for(int i = 0; i < 4; ++i) {
    for(int j = 0; j < 4; ++j) {
      ans = (ans + c[i][j]) % mod;
    }
  }
  cout << ans << endl;
}

int main() {
  long long n;
  gn(n);
  if(n == 0) {
    printf("0\n");
  }
  else if(n == 1) {
    printf("2\n");
  }
  else if(n == 2) {
    printf("4\n");
  }
  else {
    solve(mat, n - 2, MOD);
  }
  return 0;
}

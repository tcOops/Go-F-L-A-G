// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//Google mock-contest 1
//RejudgeX: 2016/8/3 22:35 - 24:00
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

long long fa[100010], fb[100010];
long long fastMul(long long n, long long k, long long MOD) {
  if(k == 0) {
    return 1 % MOD; // Bug!
  }
  long long ret = 1;
  while(k) {
    if(k & 1) {
      ret = ret * n % MOD;
    }
    k >>= 1, n = n * n % MOD;
  }
  return ret;
}


int main() {
  freopen("in.txt", "r", stdin);
   freopen("out1.txt", "w", stdout);
  long long k, n, a, b;
  int T, cases = 1;
  gn(T);
  while(T--) {
    gn(a); gn(b); gn(n); gn(k);
    long long ans = 0;
    memset(fa, 0, sizeof(fa));
    memset(fb, 0, sizeof(fb));
    for(int i = 0; i < k; ++i) {
      long long cnt = (n+1) / k;
      if((n+1) % k > i) {
        ++cnt;
      }
      if(i == 0) {
        --cnt;
      }
      cnt = cnt % MOD;
      long long res1 = fastMul(i, a, k);
      fa[res1] = (fa[res1] + cnt) % MOD;
      long long res2 = fastMul(i, b, k);
      fb[res2] = (fb[res2] + cnt) % MOD;
      if((res1 + res2) % k == 0) {
        ans = (ans + MOD - cnt) % MOD;
      }
    }

    for(int i = 1; i < k; ++i) {
      ans = ((fa[i] * fb[k - i]) % MOD + ans) % MOD;
    }
    ans = ((fa[0] * fb[0]) % MOD + ans) % MOD;
    printf("Case #%d: %lld\n", cases++, ans);
  }
  return 0;
}

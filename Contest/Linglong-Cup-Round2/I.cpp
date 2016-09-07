//AC

// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//利用二项式展开， 提取公式 sigma(C(n,2i)*k^(2i)) = ((k+1)^n + (k-1)^n) / 2;
//注意除4再取模的话， 需要求逆模

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

long long fastMul(long long n, long long k) {
  long long ret = 1;
  while(k) {
    if(k & 1) {
      ret = ret * n % MOD;
    }
    n = n * n % MOD;
    k >>= 1;
  }
  return ret;
}

int extend_gcd(long long a, long long b, long long d, long long &x, long long &y) {
  if(b == 0) {
    d = a; x = 1, y = 0;
  }
  else {
    extend_gcd(b, a%b, d, y, x);
    y-= x*(a/b);
  }
}

int main() {
  int T; gn(T);
  int cases = 1;
  while(T--) {
    long long n;
    gn(n);
    long long ans = 0;
    ans = (ans + fastMul(6, n))%MOD;
    ans = (fastMul(4, n)*2%MOD + ans)%MOD;
    ans = (fastMul(2, n) + ans)%MOD;
    long long d, x, y;
    long long rev = extend_gcd(4, MOD, d, x, y);
    printf("Case #%d: %lld\n", cases++, ans*x%MOD);
  }
  return 0;
}

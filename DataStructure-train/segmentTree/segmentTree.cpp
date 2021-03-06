//AC
// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//POJ 1661
//经典DP题， 用记忆化搜索写起来比较方便


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

long long fastMul(long long n, long long k) {
    long long ret = 1;
    while(k) {
      if(k & 1) {
        ret = ret * n%mod;
      }
      n = n * n%mod;
      k >>= 1;
    }
    return ret;
}

int main() {
  int T;
  gn(T);
  while(T--) {
    long long n;
    gn(n);
    long long ans = ((n%mod)*(n%mod)%mod+4-3*n%mod)%mod;
    ans = fastMul(2, n-1) * ans%mod;
    ans = (ans + mod - 2)%mod;
    ans = ans * 4%mod;
    cout << ans << endl;
  }
  return 0;
}

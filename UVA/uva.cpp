// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//Sb题
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

const int N = 101;
int dp[N];

int main() {
  dp[0] = 1;
  dp[1] = 1;
  for(int i = 2; i <= 40; ++i) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  int T; gn(T);
  while(T--) {
    int n; gn(n);
    string ans = "";
    for(int i = 40; i >= 1; --i) {
      if(dp[i] > n) {
        ans += "0";
        continue;
      }
      ans += "1";
      n -= dp[i];
    }

    int i;
    for(i = 0; i < ans.size(); ++i) {
      if(ans[i] != '0') break;
    }
    for(; i < ans.size(); ++i) {
      printf("%c", ans[i]);
    }
    puts("");
  }
  return 0;
}

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
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll MOD = 1000000007;

ll powMOD(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
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

const int N = 1e6 + 10;
int a[N], b[N];
int x[N], y[N];

int main() {
  int T; gn(T);
  while(T--) {
    int m, n;
    gn(m), gn(n);
    memset(x, -1, sizeof(x));
    memset(y, -1, sizeof(y));
    for(int i = 0; i < m; ++i) {
      int a; gn(a);
      if(x[a-1] == -1) {
        x[a] = 1;
      }
      else {
        x[a] = max(x[a-1] + 1, x[a]);
      }
    }
    for(int i = 0; i < n; ++i) {
      int a; gn(a);
      if(y[a-1] == -1) {
        y[a] = 1;
      }
      else {
        y[a] = max(y[a-1] + 1, y[a]);
      }
    }

    int ans = 0;
    for(int i = 1; i <= 1000000; ++i) {
      int res = min(x[i], y[i]);
      if(res > ans) {
        ans = res;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

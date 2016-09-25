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

long long n;
int ans[100010];
bool solve(long long cur, int level) {
  cout << level << endl;
  if(level == n + 1) {
    for(int i = 1; i <= n; ++i) {
      printf("%d ", ans[i]);
    }
    return true;
  }
  int idx = (int)sqrt(cur) / (level + 1);
  for(;;++idx) {
    long long tmp = idx * (level + 1);
    if(tmp >= cur) {
      long long res = sqrt(tmp);
      if(res * res == tmp) {
        if((tmp - cur) % level == 0 && res % (level + 1) == 0) {
          ans[level] = (tmp - cur) / level;
          if(solve(res, level + 1)) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

int main() {
  gn(n);
  solve(2, 1);
  return 0;
}

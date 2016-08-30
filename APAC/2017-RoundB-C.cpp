

// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

// Codeforces 365
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

const int N = 5e5 + 10;

struct point {
  int idx;
  int val, type;
  bool operator<(const point &rhs) const {
    return val < rhs.val || (val == rhs.val && type < rhs.type);
  }
}p[N];

int main() {
  int T, cases = 1;
  long long n, l, r, a, b, c1, c2, m;
  gn(T);
  while(T--) {
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &n, &l, &r, &a, &b, &c1, &c2, &m);
    p[0].idx = p[1].idx = 0;
    p[0].val = l, p[1].val = r;
    p[0].type = 0, p[1].type = 1;

    long long x = l, y = r;
    for(int i = 1; i < n; ++i) {
      long long x1 = (a*x + b*y + c1) % m;
      long long y1 = (a*x + b*y + c2) % m;
      p[i<<1] = point{i, x1, 0};
      p[i<<1|1] = point{i, y1, 1};
    }
    sort(p, p + (n<<1));

    int cnt = 0, start = -1;
    long long ans;
    for(int i = 0; i < (n<<1); ++i) {
      if(p[i].type == 0) {
        if(cnt == 0) {
          start = p[i].val;
        }
        ++cnt;
      }
      else {
        --cnt;
        if(cnt == 0) {
          ans += p[i].val - start + 1;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

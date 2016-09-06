//AC

#define DEBUG
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

const int N = 1e6 + 10;
set<int > pSet;
map<int, int> pCnt;
long long dist[N];

struct point {
  int idx;
  long long val;
  int type;
  bool operator<(const point &rhs) const {
    return val < rhs.val || (val == rhs.val && type < rhs.type);
  }
}p[N];

int main() {
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif

  int T, cases = 1;
  long long n, l, r, a, b, c1, c2, m;
  gn(T);
  while(T--) {
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &n, &l, &r, &a, &b, &c1, &c2, &m);
    p[0] = point{0, l, 0};
    p[1] = point{0, r, 1};

    long long x = l, y = r;
    for(int i = 1; i < n; ++i) {
      long long x1 = (a*x + b*y + c1) % m;
      long long y1 = (a*y + b*x + c2) % m;
      p[i<<1] = point{i, min(x1, y1), 0};
      p[i<<1|1] = point{i, max(x1, y1), 1};
      x = x1, y = y1;
    }
    sort(p, p + (n<<1));

    int cnt = 0, start = -1;
    int singleStart = -1;
    long long ans = 0;
    memset(dist, 0, sizeof(dist));

    for(int i = 0; i < (n<<1); ++i) {
      if(p[i].type == 0) {
        int top = -1;
        if(pSet.size() == 1) {
          top = *pSet.begin();
        }
        if(cnt == 0) {
          start = p[i].val;
          singleStart = p[i].val;
        }
        else {
          if(top != -1) {
    //        printf("aa %d %lld %d\n", top, p[i].val, singleStart);
            dist[top] += p[i].val - singleStart;
          }
        }
          pSet.insert(p[i].idx); ++cnt;
      }
      else {
        --cnt; pSet.erase(p[i].idx);
        if(cnt == 0) {
          ans += p[i].val - start + 1;
          dist[p[i].idx] += p[i].val - singleStart + 1;
      //    printf("bb %d %lld %d\n", p[i].idx, p[i].val, singleStart);
        }
        else if(cnt == 1) {
          singleStart = p[i].val + 1;
        }
      }
    }
    long long maxV = -1;
    for(int i = 0; i < n; ++i) {
      if(dist[i] > maxV) {
        maxV = dist[i];
      }
    }
    printf("Case #%d: %lld\n", cases++, ans - maxV);
  }
  return 0;
}

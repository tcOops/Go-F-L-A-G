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

int n, m, L, l, r, t, b;

int getCircle(int ll, int rr, int bb, int tt) {
  //inside
  if(bb >= b && tt <= t && ll >= l && rr <= r) {
  //  printf("lll\n");
    return -1;
  }

  if(tt >= t && bb >= b && bb <= t && ll >= l && rr <= r) {
    int cir = (tt - t + rr - ll) * 2;
    if(cir <= L) {
      return (tt - t) * (rr - ll);
    }
    else {
      return -1;
    }
  }

  if(ll <= l && rr >= l && rr <= r && tt <= t && bb >= b) {
    int cir = (tt - bb + l - ll) * 2;
    if(cir <= L) {
      return (tt - bb) * (l - ll);
    }
    return -1;
  }

  if(bb <= b && tt >= b && tt <= t && ll >= l && rr <= r) {
    int cir = (b - tt + rr - ll) * 2;
    if(cir <= L) {
      return (b - tt) * (rr - ll);
    }
    else {
      return -1;
    }
  }
  if(rr >= r && ll <= r && ll >= l && tt <= t && bb >= b) {
    int cir = (rr - r + tt - bb) * 2;
    if(cir <= L) {
      return (tt - bb) * (rr - r);
    }
    else {
      return -1;
    }
  }
  //0 point
  if(bb >= t || tt <= b || ll >= r || rr <= l) {
    //cout << "aaa" << endl;
    if(2*(rr - ll + tt - bb) <= L) {
      return (rr - ll) * (tt - bb);
    }
    else {
      return -1;
    }
  }

  // one point in
  if(tt >= t && bb <= t && bb >= b && ll <= l && rr >= l && rr <= r) {
    //cout << "bbb" << endl;
    int cir = 2 * (rr - ll + tt - bb);
    if(cir <= L) {
      return (rr - ll) * (tt - bb) - (t - bb) * (rr - l);
    }
    else {
      return -1;
    }
  }
  if(tt >= t && bb <= t && bb >= b && ll >= l && ll <= r && rr >= r) {
    //cout << "ccc" << endl;
    int cir = 2 * (rr - ll + tt - bb);
    if(cir <= L) {
      return (rr - ll) * (tt - bb) - (t - bb) * (r - ll);
    }
    else {
      return -1;
    }
  }
  if(tt <= t && tt >= b && bb <= b && ll <= l && rr >= l && rr <= r) {
    //cout << "ddd" << endl;
    int cir = 2 * (rr - ll + tt - bb);
    if(cir <= L) {
      return (rr - ll) * (tt - bb) - (tt - b) * (rr - l);
    }
    else {
      return -1;
    }
  }
  if(tt <= t && tt >= b && bb <= b && ll >= l && ll <= r && rr >= r) {
    //cout << "eee" << endl;
    int cir = 2 * (rr - ll + tt - bb);
    if(cir <= L) {
      return (rr - ll) * (tt - bb) - (tt - b) * (r - ll);
    }
    else {
      return -1;
    }
  }

  //two points in
  if(tt >= t && ll <= b && ll <= l && rr >= l && rr <= r) {
    //cout << "fff" << endl;
    int cir = 2 * (rr - ll + tt - bb) + 2 * (rr - l);
    if(cir <= L) {
      return (rr - ll) * (tt - bb) - (rr - l) * (t - b);
    }
    else {
      return -1;
    }
  }
  if(tt >= t && ll <= b && ll >= l && ll <= r && rr >= r) {
    //cout << "hhh" << endl;
    int cir = 2 * (rr - ll + tt - bb) + 2 * (r - ll);
    if(cir <= L) {
      return (rr - ll) * (tt - bb) - (r - ll) * (t - b);
    }
    else {
      return -1;
    }
  }
  if(ll <= l && rr >= r && tt >= t && bb <= t && bb >= b) {
    //cout << "iii" << endl;
    int cir = 2 * (rr - ll + tt - bb) + 2 * (t - bb);
    if(cir <= L) {
      return (rr - ll) * (tt - bb) - (t - bb) * (r - l);
    }
    else {
      return -1;
    }
  }
  if(ll <= l && rr >= r && tt <= t && tt >= b && bb <= b) {
    //cout << "jjj" << endl;
    int cir = 2 * (rr - ll + tt - bb) + 2 * (tt - b);
    if(cir <= L) {
      return (rr - ll) * (tt - bb) - (tt - b) * (r - l);
    }
    else {
      return -1;
    }
  }

  //four points in
  if(tt >= t && bb <= b && ll <= l && rr >= r) {
    //cout << "kkk" << endl;
    int cir = 2 * (rr - ll + tt - bb);
    if(cir <= L) {
      return (rr - ll) * (tt - bb) - (r - l) * (t - b);
    }
    else {
      return -1;
    }
  }
  return -1;
}

int main() {
  gn(n); gn(m); gn(L);
  gn(l); gn(r); gn(b); gn(t);

  int ans = 0;
  for(int i = 0; i <= n; ++i) {
    for(int j = i + 1; j <= n; ++j) {
      for(int p = 0; p <= m; ++p) {
        for(int q = p + 1; q <= m; ++q) {
          int mj = getCircle(p, q, i, j);
          if(mj > ans) {
            ans = mj;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

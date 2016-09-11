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

const int N = 1100;
bool conn[N<<1][N<<1];

struct point {
  double x1, y1, x2, y2;
}p[N];
double x[N<<1], y[N<<1];

int main() {
  int n, cases = 1;
  while(~scanf("%d", &n) && n) {
    for(int i = 0; i < n; ++i) {
      scanf("%lf%lf%lf%lf", &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
      x[i<<1] = p[i].x1, x[i<<1|1] = p[i].x2;
      y[i<<1] = p[i].y1, y[i<<1|1] = p[i].y2;
    }

    sort(x, x+(n<<1));
    sort(y, y+(n<<1));

    int cntx = 1, cnty = 1;
    for(int i = 1; i < (n<<1); ++i) {
      if(x[i] != x[cntx-1]) {
        x[cntx++] = x[i];
      }
      if(y[i] != y[cnty-1]) {
        y[cnty++] = y[i];
      }
    }

    memset(conn, false, sizeof(conn));
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < cntx - 1; ++j) {
        if(x[j] >= p[i].x2) {
          break;
        }
        if(x[j+1] <= p[i].x1) {
          continue;
        }
        for(int k = 0; k < cnty - 1; ++k) {
          if(y[k] >= p[i].y2) {
            break;
          }
          if(y[k+1] <= p[i].y1) {
            continue;
          }
          conn[j][k] = true;
        }
      }
    }

    double ans = 0.0;
    for(int i = 0; i < cntx - 1; ++i) {
      double diffx = x[i+1] - x[i];
      for(int j = 0; j < cnty - 1; ++j) {
        if(conn[i][j]) {
          ans += diffx * (y[j+1] - y[j]);
        }
      }
    }
    printf("Test case #%d\nTotal explored area: %.2lf\n\n", cases++, ans);
  }
  return 0;
}

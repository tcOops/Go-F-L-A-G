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

const int N = 110;
const int INF = 0x3f3f3f3f;
int g[N][N];
int dist[N][N][31], d[N], newD[N];
int cnt;

void add(int n, int t) {
  for(int k = 1; k <= n; ++k) {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        {
          if(dist[i][k][t-1] + dist[k][j][t-1] < dist[i][j][t]) {
            dist[i][j][t] = dist[i][k][t-1] + dist[k][j][t-1];
          }
        }
      }
    }
  }
}

void gao(int n, int m) {
  for(int t = 2; (1<<(t - 1)) <= m; ++t) {
    add(n, t);
    cnt = t;
  }
}

int main() {
  int n, m;
  gn(n); gn(m);
  memset(dist, INF, sizeof(dist));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      gn(dist[i][j][1]);
    }
  }
  for(int i = 1; i <= n; ++i) {
    dist[i][i][1] = INF;
  }
  gao(n, m);

  long long ans = 0;
  for(int i = cnt; i >= 1; --i) {
    memset(newD, INF, sizeof(newD));
    for(int j = 1; j <= n; ++j) {
      for(int k = 1; k <= n; ++k) {
        if(newD[j] > d[k] + dist[k][j][i]) {
          newD[j] = d[k] + dist[k][j][i];
        }
      }
    }
    for(int j = 1; j <= n; ++j) {
      if(newD[j] <= m) {
        memcpy(d+1, newD+1, n*sizeof(int));
        ans += (1<<(i-1));
      //  m -= 1<<(i-1);
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

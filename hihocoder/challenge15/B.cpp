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

const int N = 310;
int a[N][N], b[N][N];
int tranrow[N], trancolumn[N];
bool vis[N];
int n;

int gn_love(int x, int y) {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(a[0][j] == b[x][i]) {
        trancolumn[j] = i;
        break;
      }
    }
  }

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(a[j][0] == b[i][y]) {
        tranrow[j] = i;
        break;
      }
    }
  }

  bool suc = true;
  for(int i = 0; i < n && suc; ++i) {
    for(int j = 0; j < n; ++j) {
      if(a[i][j] != b[tranrow[i]][trancolumn[j]]) {
        suc = false;
        break;
      }
    }
  }

  if(!suc) {
    return -1;
  }

  memset(vis, false, sizeof(vis));
  int ans = 0, cnt = 0;
  for(int i = 0; i < n; ++i) {
    if(!vis[i]) {
      int j = i;
      ++cnt;
      do {
        vis[j] = true;
        j = tranrow[j];
      } while(j != i);
    }
  }
  ans = n - cnt;

  memset(vis, false, sizeof(vis));
  cnt = 0;
  for(int i = 0; i < n; ++i) {
    if(!vis[i]) {
      int j = i;
      ++cnt;
      do {
        vis[j] = true;
        j = trancolumn[j];
      } while(j != i);
    }
  }
  return (ans + n - cnt);
}

int main() {
  gn(n);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      scanf("%d", &b[i][j]);
    }
  }

  int ans = 1e9;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(a[0][0] == b[i][j]) {
  //      cout << "yes " << i << " " << j << endl;
        int res = gn_love(i, j);
        if(res != -1 && res < ans) {
          ans = res;
        }
      }
    }
  }

  if(ans == 1e9) {
    ans = -1;
  }

  cout << ans << endl;
  return 0;
}


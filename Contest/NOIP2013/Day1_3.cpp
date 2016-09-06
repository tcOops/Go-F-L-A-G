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

const int N = 1e4 + 10;
const int INF = 0x3f3f3f3f;

struct edge {
  int x, y, z;
  bool operator <(const edge &rhs) const{
    return z > rhs.z;
  }
}edges[N*5];

int fa[N], dep[N], par[N][21], L[N][21];
vector<pair<int, int > > selectEdges[N];
bool vis[N];
int ans, m, n, q;

int find(int x) {
  if(fa[x] != x) {
    fa[x] = find(fa[x]);
  }
  return fa[x];
}

void dfs(int u, int fa) {
  vis[u] = true;
  for(int i = 0; i < selectEdges[u].size(); ++i) {
    pair<int, int > t = selectEdges[u][i];
    int v = t.first, w = t.second;
    if(v == fa) continue;
    dep[v] = dep[u] + 1;
    par[v][0] = u, L[v][0] = w;
    dfs(v, u);
  }
}

void pre() {
  for(int i = 1; i <= 15; ++i) {
    for(int j = 1; j <= n; ++j) {
      par[j][i] = par[par[j][i-1]][i-1];
      L[j][i] = min(L[j][i-1], L[par[j][i-1]][i-1]);
    }
  }
}

void solve(int x, int y) {
  if(dep[x] < dep[y]) {
    swap(x, y);
  }

  int diff = dep[x] - dep[y];
  for(int i = 0; i < 15; ++i) {
    if(diff & (1<<i)) {
      ans = min(ans, L[x][i]);
      x = par[x][i];
    }
  }

  if(x == y) {
    return ;
  }

  for(int i = 14; i >= 0; --i) {
    if(par[x][i] != par[y][i]) {
      ans = min(ans, L[x][i]);
      ans = min(ans, L[y][i]);
      x = par[x][i], y = par[y][i];
    }
  }

  ans = min(ans, L[x][0]);
  ans = min(ans, L[y][0]);
}

int main() {
  gn(n); gn(m);
  for(int i = 0; i < m; ++i) {
    gn(edges[i].x); gn(edges[i].y); gn(edges[i].z);
  }
  sort(edges, edges+m);

  for(int i = 0; i < n; ++i) {
    fa[i] = i;
  }
  for(int i = 0; i < m; ++i) {
    int fx = find(edges[i].x), fy = find(edges[i].y);
    if(fx != fy) {
      fa[fx] = fy;
      selectEdges[edges[i].x].push_back(make_pair(edges[i].y, edges[i].z));
      selectEdges[edges[i].y].push_back(make_pair(edges[i].x, edges[i].z));
    }
  }

  memset(L, INF, sizeof(L));
  memset(vis, false, sizeof(vis));
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      dep[i] = 0;
      dfs(i, 0);
    }
  }

  pre();
  gn(q);
  for(int i = 0; i < q; ++i) {
    int x, y;
    gn(x); gn(y);
    ans = INF;
    if(find(x) != find(y)) {
      printf("-1\n");
    }
    else {
      solve(x, y);
      printf("%d\n", ans);
    }
  }
  return 0;
}

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

const int N = 1e5 + 10;
struct node {
  int v;
  long long w;
};
vector<node > g[N];
int son[N], lev[N];
long long val[N];
int n, m;
long long ans;

void dfs(int u, int fa) {
  son[u] = 1;
  for(auto v : g[u]) {
    if(v.v == fa) continue;
    lev[v.v] = lev[u] + 1;
    val[v.v] = v.w;
    dfs(v.v, u);
    son[u] += son[v.v];
    ans += v.w * son[v.v] * (n - son[v.v]);
  }
}

void update(int x, int y, long long z) {
  if(lev[x] < lev[y]) {
    swap(x, y);
  }
  long long delta = z - val[x];
  ans += delta * (n - son[x]) * son[x];
  val[x] = z;
}

int main() {
  gn(n); gn(m);
  for(int i = 1; i < n; ++i) {
    int x, y;
    long long z;
    gn(x); gn(y); gn(z);
    g[x].push_back(node{y, z});
    g[y].push_back(node{x, z});
  }

  dfs(1, -1);
  for(int i = 0; i < m; ++i) {
    string op;
    cin >> op;
    if(op[0] == 'E') {
      int x, y;
      long long z;
      gn(x); gn(y); gn(z);
      update(x, y, z);
    }
    else {
      cout << ans << endl;
    }
  }
  return 0;
}

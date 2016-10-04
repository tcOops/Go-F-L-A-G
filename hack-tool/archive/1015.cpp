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

int g[5][5];
int res[10], node[4];
bool vis[5];

struct seg {
  int x1, y1, x2, y2;
}segs[4];
bool suc;

bool joint() {
  for(int i = 1; i < 8; i += 2) {
    int x1, y1, x2, y2;
    if(res[i] & 1) {
      x1 = segs[res[i] >> 1].x2;
      y1 = segs[res[i] >> 1].y2;
    }
    else {
      x1 = segs[res[i] >> 1].x1;
      y1 = segs[res[i] >> 1].y1;
    }

    if(res[(i+1)%8] & 1) {
      x2 = segs[res[(i+1)%8] >> 1].x2;
      y2 = segs[res[(i+1)%8] >> 1].y2;
    }
    else {
      x2 = segs[res[(i+1)%8] >> 1].x1;
      y2 = segs[res[(i+1)%8] >> 1].y1;
    }
    if(x1 != x2 || y1 != y2) {
      return false;
    }
    return true;
  }
}

bool fits() {
  int dx1 = segs[node[0]].x2 - segs[node[0]].x1;
  int dy1 = segs[node[0]].y2 - segs[node[0]].y1;
  int dx2 = segs[node[1]].x2 - segs[node[1]].x1;
  int dy2 = segs[node[1]].y2 - segs[node[1]].y1;
  int dx3 = segs[node[2]].x2 - segs[node[2]].x1;
  int dy3 = segs[node[2]].y2 - segs[node[2]].y1;
  int dx4 = segs[node[3]].x2 - segs[node[3]].x1;
  int dy4 = segs[node[3]].y2 - segs[node[3]].y1;

  if((!dx1 && !dy1) || (!dx2 && !dy2) || (!dx3 && !dy3) || (!dx4 && !dy4)) {
    return false;
  }

  if(dx1 * dy3 != dx3 * dy1) {
    return false;
  }
  if(dx2 * dy4 != dx4 * dy2) {
    return false;
  }

  if(dx1 * dx2 + dy1 * dy2 != 0) {
    return false;
  }
  if(dx2 * dx3 + dy2 * dy3 != 0) {
    return false;
  }
  if(dx3 * dx4 + dy3 * dy4 != 0) {
    return false;
  }
  if(dx4 * dx1 + dy4 * dy1 != 0) {
    return false;
  }
  return true;
}

bool dfs(int k) {
  if(k == 4) {
    if(joint() && fits()) {
      printf("YES
");suc = true;
      return true;
    }
  }
  for(int v = 0; v < 4; ++v) {
    if(!vis[v]) {
      res[k<<1] = v<<1; res[k<<1|1] = v<<1|1; vis[v] = true;
      node[k] = v;
      if(dfs(k+1)) {
        return true;
      }
      res[k<<1] = v<<1|1; res[k<<1|1] = v<<1;
      if(dfs(k+1)) {
        return true;
      }
      vis[v] = false;
    }
  }
  return false;
}

int main() {
  int T;
  gn(T);
  while(T--) {
    for(int i = 0; i < 4; ++i) {
      gn(segs[i].x1); gn(segs[i].y1);
      gn(segs[i].x2); gn(segs[i].y2);
    }
    memset(vis, false, sizeof(vis));
    suc = false;
    dfs(0);
    if(!suc) {
      printf("NO
");
    }
  }
  return 0;
}


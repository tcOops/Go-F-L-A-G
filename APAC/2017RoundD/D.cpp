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

const int N = 10010;
const int INF = 1234567890;
int seg[N<<2], lazy[N<<2];
int n, m, l;

void pushOne(int idx, int val) {
  if(lazy[idx] == -1) {
    lazy[idx] = val;
  }
  else {
    lazy[idx] = min(lazy[idx], val);
  }
  seg[idx] = min(seg[idx], val);
}

void pushDown(int idx) {
  if(lazy[idx] != -1) {
    pushOne(idx<<1, lazy[idx]);
    pushOne(idx<<1|1, lazy[idx]);
    lazy[idx] = -1;
  }
}

void pushUp(int idx) {
  seg[idx] = min(seg[idx<<1], seg[idx<<1|1]);
}

void build(int idx, int l, int r) {
  if(l == r) {
    seg[idx] = ((r == 0) ? 0 : INF);
    return ;
  }
  lazy[idx] = -1;
  int mid = l + r >> 1;
  build(idx<<1, l, mid);
  build(idx<<1|1, mid+1, r);
  pushUp(idx);
}

void modify(int idx, int l, int r, int pos, int val) {
  if(l == r) {
    seg[idx] = min(seg[idx], val);
    //pushOne(idx, val);
    return ;
  }
  pushDown(idx);
  int mid = l + r >> 1;
  if(pos <= mid) {
    modify(idx<<1, l, mid, pos, val);
  }
  else {
    modify(idx<<1|1, mid+1, r, pos, val);
  }
  pushUp(idx);
}

int query(int idx, int l, int r, int L, int R) {
  if(l >= L && r <= R) {
    return seg[idx];
  }
  pushDown(idx);
  int mid = l + r >> 1;
  int ret = INF;
  if(L <= mid) {
    ret = min(ret, query(idx<<1, l, mid, L, R));
  }
  if(R > mid) {
    ret = min(ret, query(idx<<1|1, mid+1, r, L, R));
  }
  return ret;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
  int T, cases = 1; gn(T);
  while(T--) {
    gn(n); gn(m); gn(l);
    build(1, 0, l);
    for(int i = 1; i <= n; ++i) {
      int a, b, c;
      gn(a); gn(b); gn(c);
      for(int j = l; j >= a; --j) {
        int w = query(1, 0, l, max(j - b, 0), j - a);
        if(w >= INF) continue;
        modify(1, 0, l, j, w + c);
      }
    }

    int ans = query(1, 0, l, l, l);
    printf("Case #%d: ", cases++);
    if(ans > m) {
      printf("IMPOSSIBLE\n");
    }
    else {
      printf("%d\n", ans);
    }
  }
  return 0;
}

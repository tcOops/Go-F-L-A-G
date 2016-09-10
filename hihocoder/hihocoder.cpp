//AC

// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//
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

const int N = 1000010;
const int INF = 1e9;
int sum[N<<2], col[N<<2];
void pushUp(int idx) {
  sum[idx] = sum[idx<<1] + sum[idx<<1|1];
}

void pushDown(int idx, int l, int r) {
  int mid = (l + r) >> 1;
  sum[idx<<1] = col[idx]*(mid - l + 1);
  sum[idx<<1|1] = col[idx]*(r - mid);
  col[idx<<1] = col[idx<<1|1] = col[idx];
  col[idx] = -1;
}

void build(int idx, int l, int r) {
  if(l == r) {
    gn(sum[idx]);
    col[idx] = sum[idx];
    return ;
  }
  int mid = (l + r) >> 1;
  build(idx<<1, l, mid);
  build(idx<<1|1, mid+1, r);
  pushUp(idx);
}

void modify(int idx, int l, int r, int L, int R, int val) {
  if(l >= L && r <= R) {
    sum[idx] = val * (r - l + 1);
    col[idx] = val;
    return ;
  }

  if(col[idx] != -1) {
    pushDown(idx, l, r);
  }
  int mid = (l + r) >> 1;
  if(L <= mid) {
    modify(idx<<1, l, mid, L, R, val);
  }
  if(R > mid){
    modify(idx<<1|1, mid+1, r, L, R, val);
  }
  pushUp(idx);
}

int query(int idx, int l, int r, int L, int R) {
  if(l >= L && r <= R) {
    return sum[idx];
  }

  if(col[idx] != -1) {
    pushDown(idx, l, r);
  }
  int mid = (l + r) >> 1;
  int ret = 0;
  if(mid >= L) {
    ret = ret + query(idx<<1, l, mid, L, R);
  }
  if(mid < R) {
    ret = ret + query(idx<<1|1, mid+1, r, L, R);
  }
  return ret;
}

int main() {
  int n, m;
  gn(n);
  memset(col, -1, sizeof(col));
  build(1, 1, n);
  gn(m);
  for(int i = 1; i <= m; ++i) {
    int x, y, z, p;
    gn(x);
    if(x == 0) {
      gn(y); gn(z);
      int ans = query(1, 1, n, y, z);
      cout << ans << endl;
    }
    else {
      gn(y); gn(z); gn(p);
      modify(1, 1, n, y, z, p);
    }
  }
  return 0;
}

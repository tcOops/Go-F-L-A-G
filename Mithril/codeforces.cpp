

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
int a[N], c[N];
int sum[N], ans[N];
int n, m;
map<int, int> mp;

struct QUERY {
  int l, r;
  int id;
  bool operator <(const QUERY &rhs) const {
    return r < rhs.r || (r == rhs.r && l < rhs.l);
  }
}query[N];

void update(int idx, int v) {
  while(idx <= n) {
    c[idx] ^= v;
    idx += idx & (-idx);
  }
}

int get(int idx) {
  int ret = 0;
  while(idx) {
    ret ^= c[idx];
    idx = idx & (idx - 1);
  }
  return ret;
}

int main() {
  gn(n);

  sum[0] = 0;
  for(int i = 1; i <= n; ++i) {
    gn(a[i]);
    sum[i] = sum[i-1] ^ a[i];
  }

  gn(m);
  for(int i = 1; i <= m; ++i) {
    gn(query[i].l); gn(query[i].r);
    query[i].id = i;
  }
  sort(query+1, query+1+m);

  int j = 1;
  for(int i = 1; i <= n; ++i) {
    if(mp.find(a[i]) == mp.end()) {
      mp[a[i]] = i;
    }
    else {
      update(mp[a[i]], a[i]);
      mp[a[i]] = i;
    }
    update(i, a[i]);

    if(query[j].r == i) {
      while(j <= m && query[j].r == i) {
        int rv = get(query[j].r) ^ sum[query[j].r];
        ans[query[j].id] = rv ^ get(query[j].l - 1) ^ sum[query[j].l - 1];
        ++j;
      }
      if(j > m) break;
    }
  }

  for(int i = 1; i <= m; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}

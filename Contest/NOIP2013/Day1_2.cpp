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
const ll MOD = 99999997;
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
  int id, w;
  bool operator <(const node &rhs) const {
    return w < rhs.w;
  }
}a[N], b[N];

int n, c[N], d[N];

void update(int pos, int k) {
  while(pos <= n) {
    c[pos] += k;
    pos += pos&(-pos);
  }
}

long long query(int pos) {
  long long ret = 0;
  while(pos > 0) {
    ret += c[pos];
    pos -= pos&(-pos);
  }
  return ret;
}

int main() {
  gn(n);
  for(int i = 1; i <= n; ++i) {
    gn(a[i].w);
    a[i].id = i;
  }
  for(int i = 1; i <= n; ++i) {
    gn(b[i].w);
    b[i].id = i;
  }
  sort(a+1, a+1+n);
  sort(b+1, b+1+n);

  for(int i = 1; i <= n; ++i) {
    d[b[i].id] = a[i].id;
  }

  memset(c, 0, sizeof(c));
  long long ans = 0;
  for(int i = 1; i <= n; ++i) {
    ans =  (ans + i - 1 - query(d[i] - 1) + MOD) % MOD;
    update(d[i], 1);
  }
  cout << ans << endl;
  return 0;
}

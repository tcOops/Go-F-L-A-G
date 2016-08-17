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

const int N = 1010;

int n, m;
long long c[N][N];
#define lowbit(x) (x & (-x))

void add(int r, int c_, int val) {
  for(int x = r; x <= n; x += lowbit(x)) {
    for(int y = c_; y <= n; y += lowbit(y)) {
      c[x][y] += val;
    }
  }
}

long long getSum(int r, int c_) {
  long long ret = 0;
  for(int x = r; x > 0; x -= lowbit(x)) {
    for(int y = c_; y > 0; y -= lowbit(y)) {
      ret += c[x][y];
    }
  }
  return ret;
}

long long getSum(int tr, int tc, int br, int bc) {
  long long ret = 0;
  ret = (getSum(br, bc) - getSum(br, tc-1) - getSum(tr-1, bc) + getSum(tr-1, tc-1)) % MOD;
  while(ret < 0) {
    ret += MOD;
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);

  memset(c, 0, sizeof(c));
  for(int i = 0; i < m; ++i) {
    string op; cin >> op;
    if(op[0] == 'A') {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      ++x, ++y;
      add(x, y, z);
    }
    else {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      ++x1, ++y1, ++x2, ++y2;
      printf("%lld\n", getSum(x1, y1, x2, y2));
    }
  }
  return 0;
}

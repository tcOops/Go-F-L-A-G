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

const int N = 1e5 + 10;

struct Matrix {
  long long s[2][2];

  Matrix() {
    memset(s, 0, sizeof(s));
  }

  Matrix operator *(const Matrix &rhs) const {
    Matrix ret;
    for(int i = 0; i < 2; ++i) {
      for(int j = 0; j < 2; ++j) {
        for(int k = 0; k < 2; ++k) {
          ret.s[i][j] = (s[i][k]*rhs.s[k][j]%MOD + ret.s[i][j]) % MOD;
        }
      }
    }
    return ret;
  }

  Matrix operator ^(const long long &fixedPar) const {
    long long k = fixedPar;
    Matrix ret, tmp = *this;
    for(int i = 0; i < 2; ++i) {
      ret.s[i][i] = 1;
    }

    while(k) {
      if(k & 1) {
        ret = ret * tmp;
      }
      k >>= 1;
      tmp = tmp * tmp;
    }
    return ret;
  }
};

long long sum[N<<2][2];
Matrix lazy[N<<2];
bool col[N<<2];

void pushUp(int idx) {
  sum[idx][0] = (sum[idx<<1][0] + sum[idx<<1|1][0]) % MOD;
  sum[idx][1] = (sum[idx<<1][1] + sum[idx<<1|1][1]) % MOD;
}

void pushOne(int idx, Matrix x) {
  if(!col[idx]) {
    lazy[idx] = x;
    col[idx] = true;
  }
  else {
    lazy[idx] = lazy[idx] * x;
  }

  Matrix B;
  B.s[0][0] = sum[idx][0];
  B.s[1][0] = sum[idx][1];
  B = x * B;
  sum[idx][0] = B.s[0][0], sum[idx][1] = B.s[1][0];
}

void pushDown(int idx) {
  if(col[idx]) {
    pushOne(idx<<1, lazy[idx]);
    pushOne(idx<<1|1, lazy[idx]);
    col[idx] = false;
  }
}

void build(int idx, int l, int r) {
  if(l == r) {
    sum[idx][0] = 1, sum[idx][1] = 0;
    return ;
  }
  col[idx] = false;
  int mid = (l + r) >> 1;
  build(idx<<1, l, mid);
  build(idx<<1|1, mid+1, r);
  pushUp(idx);
}

void modify(int idx, int l, int r, int L, int R, Matrix x) {
  if(L <= l && R >= r) {
    pushOne(idx, x);
    return ;
  }

  int mid = (l + r) >> 1;
  pushDown(idx);
  if(mid >= L) {
    modify(idx<<1, l, mid, L, R, x);
  }
  if(mid + 1 <= R) {
    modify(idx<<1|1, mid+1, r, L, R, x);
  }
  pushUp(idx);
}

long long query(int idx, int l, int r, int L, int R) {
  if(L <= l && R >= r) {
    return sum[idx][1];
  }

  int mid = (l + r) >> 1;
  pushDown(idx);

  long long ret = 0;
  if(mid >= L) {
    ret += query(idx<<1, l, mid, L, R);
  }
  if(mid + 1 <= R) {
    ret += query(idx<<1|1, mid+1, r, L, R);
  }
  return ret % MOD;
}

int main() {
  //freopen("in.txt", "r", stdin);
  int n, m;
  gn(n); gn(m);
  Matrix fib;
  fib.s[0][0] = fib.s[0][1] = fib.s[1][0] = 1;
  build(1, 1, n);

  for(int i = 0; i < n; ++i) {
    int x; gn(x);
    Matrix B = fib ^ x;
    modify(1, 1, n, i+1, i+1, B);
  }

  for(int i = 0; i < m; ++i) {
    int op, x, y, z;
    gn(op);
    if(op == 1) {
      gn(x); gn(y); gn(z);
      Matrix B = fib ^ z;
      modify(1, 1, n, x, y, B);
    }
    else {
      gn(x); gn(y);
      printf("%lld\n", query(1, 1, n, x, y));
    }
  }
  return 0;
}

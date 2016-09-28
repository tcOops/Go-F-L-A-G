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
#include <bitset>
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

const int N = 1e6 + 10;
long long m, n;
int ans[100];

void solve(long long n, bool canZero, long long m, int cnt, int len) {
  cout << n << endl;
  if(n < 10) {
    ans[cnt] = canZero ? m - 1 : m;
    int i = 0;
    for(;;++i) {
      if(ans[i] != 0) break;
    }
    for(; i < len; ++i) {
      printf("%d", ans[i]);
    }
    return ;
  }

  long long dig = n, bb = 1;
  while(dig >= 10) {
    dig /= 10;
    bb = bb * 10;
  }
  int start = canZero ? 0 : 1;
  if(dig == start) {
    solve(bb, false, m, cnt + 1, len - 1);
    return ;
  }
  long long base = 1, sum = 0;
  for(int i = 0; i < len; ++i) {
    sum += base;
    base *= 10;
  }
  int cn = m / sum;
  int cur = start + cn - 1;
  if(m % sum != 0) {
    ++cur;
  }
  ans[cnt] = cur;
  long long nxt;
  if(cur == dig) {
    nxt = bb;
  }
  else {
    nxt = n - bb * dig;
  }
  solve(nxt, true, m - sum * (cur - start), cnt + 1, len - 1);
}

int main() {
  gn(n); gn(m);
  int len = 0;
  long long res = n;
  while(res) {
    res /= 10;
    ++len;
  }
  solve(n, true, m, 0, len);
  return 0;
}

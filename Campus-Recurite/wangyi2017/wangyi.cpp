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


<<<<<<< HEAD
void solve(long long n, bool canZero, long long m, int cnt, int len) {
  cout << n << " " << m << endl;
  if(n <= 10) {
    ans[cnt] = canZero ? m - 1 : m;
    int i = 0;
    for(;;++i) {
      if(ans[i] != 0) break;
    }
    for(; i < len; ++i) {
      printf("%d", ans[i]);
=======
#define LL long long
LL n, m, k, ans, e, pre[1000010], inv[1000010];

LL pow_mod(LL a, LL n) {
    a %= MOD;
    LL ret = 1;
    while (n) {
        if (n&1) ret = (ret*a)%MOD;
        a = (a*a)%MOD;
        n >>= 1;
>>>>>>> c0d77caab8db656996ddcb0f9ffbd08f5e0b629f
    }
    return ret;
}

<<<<<<< HEAD
  long long dig = n, bb = 1;
  while(dig >= 10) {
    dig /= 10;
    bb = bb * 10;
  }
  int start = canZero ? 0 : 1;
  if(dig == start) {
    cout << "cccc" << endl;
    solve(bb, false, m - (n - bb + 1), cnt + 1, len - 1);
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
=======
void init() {
    pre[0] = 1;
    for (int i = 1; i <= 1000000; i++) pre[i] = pre[i-1]*i%MOD;
    inv[0] = 1;
    for (int i = 1; i <= 1000000; i++) inv[i] = pow_mod(pre[i], MOD-2)%MOD;
>>>>>>> c0d77caab8db656996ddcb0f9ffbd08f5e0b629f
}

LL C(LL x, LL y) {
    if (x <= 1 || y == 0) return 1;
    LL t = pre[x];
    t = t*inv[y]%MOD*inv[x-y]%MOD;
    return t;
}


int main() {
<<<<<<< HEAD
  gn(n); gn(m);
  int len = 0;
  long long res = n;
  while(res) {
    res /= 10;
    ++len;
  }
  solve(n, false, m, 0, len);
  return 0;
=======
    init();
    int tt;
    scanf("%d", &tt);
    for (int cases = 1; cases <= tt; cases++) {
        scanf("%lld %lld", &n, &m);
        k = 1;
        if (m == 1) {
            printf("%lld\n", n);
            continue;
        }
        e = n-m*(k+1);
        if (e < 0) {
            printf("0\n");
            continue;
        }
        ans = C(m+e-1, e)*n%MOD*pre[m-1]%MOD;
        printf("%lld\n", ans);
    }
>>>>>>> c0d77caab8db656996ddcb0f9ffbd08f5e0b629f
}

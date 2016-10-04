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


#define LL long long
LL n, m, k, ans, e, pre[1000010], inv[1000010];

LL pow_mod(LL a, LL n) {
    a %= MOD;
    LL ret = 1;
    while (n) {
        if (n&1) ret = (ret*a)%MOD;
        a = (a*a)%MOD;
        n >>= 1;
    }
    return ret;
}

void init() {
    pre[0] = 1;
    for (int i = 1; i <= 1000000; i++) pre[i] = pre[i-1]*i%MOD;
    inv[0] = 1;
    for (int i = 1; i <= 1000000; i++) inv[i] = pow_mod(pre[i], MOD-2)%MOD;
}

LL C(LL x, LL y) {
    if (x <= 1 || y == 0) return 1;
    LL t = pre[x];
    t = t*inv[y]%MOD*inv[x-y]%MOD;
    return t;
}


int main() {
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
}

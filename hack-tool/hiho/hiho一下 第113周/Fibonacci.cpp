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

const int N = 1e6 + 10;
int fib[1010];
long long dp[1010];

int main() {
    ios_base::sync_with_stdio(0);
    int n; gn(n);
    fib[1] = 1, fib[2] = 1;
    int cnt;
    for(int i = 3; ; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
        if(fib[i] > 1e5) break;
        cnt = i;
    }
    
    for(int i = 1; i <= n; ++i) {
        int x; gn(x);
        if(x == 1) {
            dp[2] = (dp[2] + dp[1]) % MOD;
            ++dp[1];
        }
        else {
            int pos = lower_bound(fib+1, fib+cnt+1, x) - fib;
            if(fib[pos] == x) {
                dp[pos] = (dp[pos-1] + dp[pos]) % MOD;
            }
        }
    }
    
    long long ans = 0;
    for(int i = 1; fib[i] <= 1e5; ++i) {
    //    printf("%d %d\n", i, dp[i]);
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}
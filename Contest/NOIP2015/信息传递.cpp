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

const int N = 200010;
int vis[N];
int a[N], pre[N], ans;

void dfs(int k, int cnt) {
    if(vis[k] == 1) {
   //     printf("%d %d %d \n", k, cnt, pre[k]);
        ans = min(ans, cnt - pre[k]);
    }
    else if(vis[k] == 0){
        vis[k] = 1; pre[k] = cnt;
        dfs(a[k], cnt + 1);
        vis[k] = 2;
    }
}

int main() {
    int n; gn(n);
    for(int i = 1; i <= n; ++i) {
        gn(a[i]);
    }
    
    ans = n;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; ++i) {
        if(vis[i] == 0) {
            dfs(i, 0);
        }
    }
    cout << ans << endl;
    return 0;
}


// Author:tcOops
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
typedef long long ll;
#define rep(i,s,t) for(int i=int(s); i<int(t); i++)
#define mst(A,k) memset(A,k,sizeof(A))
#define sz(A) (int(A.size()))
using namespace std;

int n, a[55];
vector<int> Ax[8195];
vector<ll> dp[2][8192];
int mp[8192];

int main() {
    //freopen("in.txt","r",stdin);
    
    rep(i, 0, 8192)
    {
        rep(j, 0, 8192)
        {
            if((i & j) == i || (i & j) == 0)
            {
                Ax[i].push_back(j);
                dp[0][i].push_back(0);
                dp[1][i].push_back(0);
            }
        }
    }
    while(~scanf("%d", &n))
    {
        rep(i, 0, n) scanf("%d", a + i);
        int cnt = 0;
        rep(i, 0, 8192)
        rep(j, 0, sz(Ax[i]))
        dp[cnt][i][j] = 0;
        rep(i, 0, n)
        {
            cnt ^= 1;
            rep(j, 0, 8192)
            rep(k, 0, sz(Ax[j]))
            {
                dp[cnt][j][k] = dp[1-cnt][j][k];
                if(j == a[i] && Ax[j][k] == j)
                {
                    dp[cnt][j][k]++;
                }
            }
            rep(j, 0, 8192)
            {
                int c = a[i] & j;
                rep(k, 0, sz(Ax[c])) mp[Ax[c][k]] = k;
                rep(k, 0, sz(Ax[j])) if(dp[1-cnt][j][k])
                {
                    int v = mp[Ax[j][k] ^ a[i]];
                    dp[cnt][c][v] += dp[1-cnt][j][k];
                }
            }
        }
        ll ans = 0;
        rep(i, 0, 8192)
        {
            rep(j, 0, sz(Ax[i])) if(Ax[i][j] == i && dp[cnt][i][j])
            {
                ans += dp[cnt][i][j];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}



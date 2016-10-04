// Author:tcOops
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
#define maxab(a, b) ((a) > (b) ? (a) : (b))
const int N = 1010;

int cab[N];
int dp[N][1<<11];

int cal(int s, int m) {
    int ret = 0;
    for(int i = 0; i < m; ++i) {
        if(s & (1<<i)) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &cab[i]);
    }
    
    memset(dp, 0, sizeof(dp));
   // dp[1][1] = cab[1];
    for(int i = 0; i < n; ++i) {
        for(int s = 0; s < (1 << (m-1)); ++s) {
            int bits = cal(s, m-1);
            if(bits > q) {
                continue;
            }
            if(bits < q) {
                dp[i+1][s>>1 | (1<<(m-2))] = maxab(dp[i][s] + cab[i+1], dp[i+1][s>>1 | (1<<(m-2))]);
            }
            dp[i+1][s>>1] = maxab(dp[i][s], dp[i+1][s>>1]);
        }
    }
    
    int ans = 0;
    for(int s = 0; s < (1<<(m-1)); ++s) {
        if(dp[n][s] > ans) {
            ans = dp[n][s];
        }
    }
    printf("%d\n", ans);
    return 0;
}


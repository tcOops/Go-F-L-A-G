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
using namespace std;
const int N = 110;
const int MOD = 1e9 + 7;

int dp[N][2];

int main() {
    int n;
    scanf("%d", &n);
    
    dp[1][0] = 1, dp[1][1] = 1;
    long long ans = 1;
    for(int i = 1; i <= n; ++i) {
        ans = ans * 2 % MOD;
    }
    
    for(int i = 2; i <= n; ++i) {
        dp[i][1] = dp[i-1][0];
        dp[i][0] = (dp[i-1][0] + dp[i-1][1])%MOD;
    }
    printf("%d\n", (ans + 2 * MOD - dp[n][0] - dp[n][1])%MOD);
    return 0;
}
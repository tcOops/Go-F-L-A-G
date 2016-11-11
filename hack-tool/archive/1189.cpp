#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 998244353;
const int N = 500010;
char s[N];
int a[N], last[30];
long long dp[N], sum[N];

long long Rev(long long a, long long b) {
    long long ret = 1;
    while(b) {
        if(b & 1) {
            ret = ret * a % MOD;
        }
        b >>= 1, a = a * a % MOD;
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    long long rev = Rev(100, MOD - 2);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1] * a[i] % MOD + ((dp[i-1] * 2 + MOD - sum[last[s[i]-'a']]) * (100 - a[i]) % MOD);
        dp[i] = dp[i] % MOD * rev % MOD;
        sum[i] = dp[i-1] * (100 - a[i]) % MOD + (sum[last[s[i]-'a']] * a[i] % MOD);
        sum[i] = sum[i] * rev % MOD;
        last[s[i]-'a'] = i;
    }
    printf("%lld\n", (dp[n] + MOD) % MOD);
    return 0;
}

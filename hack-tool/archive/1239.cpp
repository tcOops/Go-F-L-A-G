#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000010;
const int MOD = 1e9 + 7;

int dp[200000];
int a[N], fib[200000];

void solve(int n, int &idx) {
    int f1 = 1, f2 = 1;
    while(f1 <= 100000) {
        fib[idx++] = f1;
        f2 = f1 + f2;
        f1 = f2 - f1;
    }
    
    for(int i = 0; i < n; ++i) {
        if(a[i] == 0) continue;
        if(a[i] == 1) {
            dp[2] = (dp[1] + dp[2])%MOD;
            dp[1] = (dp[1] + 1)%MOD;
        }
        else {
            int pos = lower_bound(fib+1, fib+idx, a[i]) - fib;
            if(fib[pos] == a[i]) {
                dp[pos] = (dp[pos-1] + dp[pos])%MOD;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    memset(dp, 0, sizeof(dp));
    int idx = 1;
    solve(n, idx);
    
    int ans = 0;
    for(int i = 1; i < idx; ++i) {
        ans = (ans + dp[i])%MOD;
    }
    printf("%d\n", ans);
    return 0;
}
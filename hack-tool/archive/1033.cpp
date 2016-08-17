// Author:tcOops
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 21;
const int MOD = 1e9 + 7;
const int OFFSET = 210;

long long dig[N], base[N];

struct google {
    long long n, sum;
    google() {
        n = -1, sum = 0;
    }
};
google dp[N][N][420];


google solve(int len, int digital, long long sum, bool isPrefix0, bool limit) {
 //   printf("%d %d %lld\n", len, digital, sum);
    google ans, res;
    ans.n = 0, ans.sum = 0;
    
    if(len < 0) {
        return ans;
    }
    
    if(!limit && isPrefix0 && dp[len][digital][sum+OFFSET].n != -1) {
        return dp[len][digital][sum+OFFSET];
    }
    
    if(len == 0) {
        if(digital == sum) {
            ans.sum = (long long)sum;
            ans.n = (long long)1;
            return ans;
        }
        return ans;
    }
    
    int up = limit ? dig[len-1] : 9;
    long long new_sum = digital - sum;
    
    for(int i = 0; i <= up; ++i) {
        if(!isPrefix0) {
            res = solve(len-1, i, sum, i != 0, limit && (i == up));
        }
        else {
            res = solve(len-1, i, new_sum, true, limit && (i == up));
        }
        
        ans.n += res.n;
        ans.sum = ((ans.sum + res.sum) % MOD + (res.n*digital) % MOD * base[len] % MOD + MOD) % MOD;
    }
    
    //printf("%lld %lld\n", ans.n, ans.sum);
    if(!limit && isPrefix0) {
        dp[len][digital][sum+OFFSET] = ans;
    }
    return ans;
}


long long go(long long n, long long k) {
    if(n <= 0) {
        return 0;
    }
    
    int len = 0;
    while(n) {
        dig[len++] = n%10;
        n /= 10;
    }
    dig[len++] = 0;
    return solve(len-1, 0, k, false, true).sum;
}


int main () {
    long long l, r, k;
    base[0] = 1;
    for(int i = 1; i < N; ++i) {
        base[i] = (base[i-1] * 10) % MOD;
    }
    
    scanf("%lld %lld %lld", &l, &r, &k);
    printf("%lld\n", (go(r, k) - go(l-1, k) + MOD) % MOD);
    return 0;
}

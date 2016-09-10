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

int dig[N];
long long base[N];

struct google {
    long long n, sum;
    google() {
        n = -1, sum = 0;
    }
};
google dp[N][420];


google solve(int len, long long sum, bool isPrefix0, bool limit) {
    //printf("%d %d %lld\n", len, digital, sum);
    google ans, res;
    ans.n = 0, ans.sum = 0;
    
    if(len == 0) {
        if(sum == 0) {
            ans.n = 1;
        }
        return ans;
    }
    
    if(!limit && isPrefix0 && dp[len][sum+OFFSET].n != -1) {
        return dp[len][sum+OFFSET];
    }
    
    int up = limit ? dig[len] : 9;
    
    for(int i = 0; i <= up; ++i) {
        if(!isPrefix0) {
            if(i == 0) {
                res = solve(len-1, sum, false, limit && (i == up));
            }
            else {
                res = solve(len-1, i-sum, true, limit && (i == up));
            }
        }
        else {
            long long new_sum = i - sum;
            res = solve(len-1, new_sum, true, limit && (i == up));
        }
        
        ans.n += res.n;
        ans.sum = ((ans.sum + res.sum) % MOD + (res.n*i) % MOD * base[len-1] % MOD + MOD) % MOD;
    }
    
    //printf("%lld %lld\n", ans.n, ans.sum);
    if(!limit && isPrefix0) {
        dp[len][sum+OFFSET] = ans;
    }
    return ans;
}


long long go(long long n, long long k) {
    if(n <= 0) {
        return 0;
    }
    
    int len = 0;
    while(n) {
        dig[++len] = n%10;
        n /= 10;
    }
   // dig[len++] = 0;
    return solve(len, k, false, true).sum;
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


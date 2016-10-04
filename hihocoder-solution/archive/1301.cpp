// Author:tcOops
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

// Codeforces Round #353 (Div. 2)

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
const int N = 21;

long long dp[N][2];
int dig[N];

long long solve(int len, bool has, bool limit) {
    if(len == 0) {
        if(has) {
            return 1;
        }
        return 0;
    }
    
    if(!limit && dp[len][has] != -1) {
        return dp[len][has];
    }
    
    int up = limit ? dig[len] : 9;
 //   printf("%d %d %d\n", limit, len, up);
    
    long long sum = 0;
    for(int i = 0; i <= up; ++i) {
        if(has) {
            sum += solve(len-1, has, limit && (i == up));
        }
        else {
            if(i == 4 || i == 7) {
                sum += solve(len-1, true, limit && (i == up));
            }
            else {
                sum += solve(len-1, false, limit && (i == up));
            }
        }
    }
    
    if(!limit) {
        dp[len][has] = sum;
    }
    return sum;
}

long long go(long long n) {
    memset(dp, -1, sizeof(dp));
    int len = 0;
    while(n) {
        dig[++len] = n % 10;
        n /= 10;
    }
    long long ans = solve(len, false, true);
    return ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    long long k;
    scanf("%lld", &k);
    
   // go(1e19);
    long long l = 1, r = 1e19;
    while(l <= r) {
        long long mid = (l + r) >> 1;
        long long ans = go(mid);
        if(ans == k) {
            while(ans == go(mid)) {
                mid--;
            }
            printf("%lld\n", mid+1);
            return 0;
        }
        if(ans < k) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
  
    return 0;
}
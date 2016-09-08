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
#define minab(a, b) ((a) < (b) ? (a) : (b))
const int N = 5000010;

int phi[N];
int dp[N][24];

void pre() {
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for(int i = 2; i < N; ++i) {
        if(phi[i] == 0) {
            for(int j = i; j < N; j += i) {
                if(phi[j] == 0) {
                    phi[j] = j;
                }
                phi[j] = phi[j] / i * (i-1);
            }
        }
    }
    
    /*
    for(int i = 1; i < N; ++i) {
        dp[i][0] = phi[i];
    }
    for(int j = 1; j < 24; ++j) {
        for(int i = 1; i+(1<<j)-1 < N; ++i) {
            int k = i + (1<<(j-1));
            dp[i][j] = minab(dp[i][j-1], dp[k][j-1]);
        }
    }
    */
}

void solve(int left, int right) {
    int range = right - left + 1;
    int l = 0, r = range;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if((1 << mid) > range) {
            r = mid - 1;
        }
        else {
            l = mid;
        }
    }
    
    int ans = minab(dp[left][l], dp[right - (1<<l) + 1][l]);
    printf("%d\n", ans);
}

int main() {
    pre();
    
    int l, r;
    scanf("%d %d", &l, &r);
    int ans = 1e9, id;
    for(int i = l; i <= r; ++i) {
        if(phi[i] < ans) {
            ans = phi[i];
            id = i;
        }
    }
    printf("%d\n", id);
 //   solve(l, r);
    return 0;
}
urn 0;
}

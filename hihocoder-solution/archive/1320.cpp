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

int p[N][N], dp[N][N];
char comp[N];

void pre(char *str, int idx, int len) {
    p[idx][idx] = idx - 1;
    int j = idx - 1;
    for(int i = idx + 1; i < len; ++i) {
        while(j >= idx && str[j+1] != str[i]) {
            j = p[idx][j];
        }
        if(str[j+1] == str[i]) {
            ++j;
        }
        p[idx][i] = j;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", comp);
        int len = strlen(comp);
        for(int j = 0; j < len; ++j) {
            pre(comp, j, len);
        }
        
        // memset(dp, 0x3f3f3f3f, sizeof(dp));
        for(int i = 0; i < len; ++i) {
            dp[i][i] = 1;
        }
        
        for(int k = 2; k <= len; ++k) {
            for(int i = 0; i + k - 1 < len; ++i) {
                int j = i + k - 1, cnt;
                if(k % (j - p[i][j]) != 0) {
                    cnt = 1;
                }
                else {
                    cnt = k / (j - p[i][j]);
                }
                
                if(cnt == 1) {
                    dp[i][j] = k;
                }
                if(cnt > 1 && cnt < 10) {
                    dp[i][j] = 1 + 2 + dp[i][i+j-p[i][j]-1];
                }
                if(cnt >= 10 && cnt <= 99) {
                    dp[i][j] = 2 + 2 + dp[i][i+j-p[i][j]-1];
                }
                if(cnt >= 100) {
                    dp[i][j] = 3 + 2 + dp[i][i+j-p[i][j]-1];
                }
                
                for(int d = i; d < j; ++d) {
                    if(dp[i][d] + dp[d+1][j] < dp[i][j]) {
                        dp[i][j] = dp[i][d] + dp[d+1][j];
                    }
                }
            }
        }
        printf("%d\n", dp[0][len-1]);
    }
    return 0;
}
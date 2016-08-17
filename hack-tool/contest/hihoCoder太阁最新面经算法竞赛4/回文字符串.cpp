// Author : rejudgeX
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
typedef long long LL;
const int M = 510;
const long long INF = (long long)1 << 50;
const int N = 110;

string a, reva;
int dp[N][N];

int min(int a, int b, int c) {
    int ret = a;
    if(b < ret) {
        ret = b;
    }
    if(c < ret) {
        ret = c;
    }
    return ret;
}

int main() {
    cin >> a;
    int len = (int)a.size();
    
    memset(dp, 0, sizeof(dp));
    
    for(int k = 2; k <= len; ++k) {
        for(int i = 0; i + k - 1 < len; ++i) {
            int j = i + k - 1;
            if(a[i] == a[j]) {
                dp[i][j] = dp[i+1][j-1];
            }
            else {
                dp[i][j] = min(dp[i][j-1], dp[i+1][j], dp[i+1][j-1]) + 1;
            }
        }
    }
    
    printf("%d\n", dp[0][len-1]);
    return 0;
}
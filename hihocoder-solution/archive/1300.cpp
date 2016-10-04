// Author:tcOops
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

// Hihocoder -> 1195
//Gauss Elimination

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;

int dp[N], stack[N];
string bracket;

int main() {
    cin >> bracket;
    int top = 0, ans = 0;
    for(int i = 0; i < bracket.size(); ++i) {
        if(bracket[i] == '(') {
            stack[top++] = i + 1;
        }
        else {
            if(top != 0) {
                dp[i+1] = 1;
                dp[i+1] += dp[stack[--top] - 1];
            }
            ans += dp[i+1];
        }
    }
    printf("%d\n", ans);
    return 0;
}
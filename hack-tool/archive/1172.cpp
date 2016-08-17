// Author:tcOops
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
    string chs;
    int n, ans = 0;
    cin >> n >> chs;
    for(int i = 0; i < n; ++i) {
        if(chs[i] == 'H') {
            ans ^= (i + 1);
        }
    }
    if(ans) {
        printf("Alice\n");
    }
    else {
        printf("Bob\n");
    }
    return 0;
}
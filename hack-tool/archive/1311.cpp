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
const int N = 51;
typedef pair<int, int> pii;

void solve(string dot) {
    bool suc = true;
    string ans = "0.";
    for(int i = (int)dot.size() - 1; i >= 2; --i) {
        if((dot[i] - '0') % 5 != 0) {
            suc = false;
            break;
        }
        
        int d = 0;
        for(int j = i; j >= 2; --j) {
            int tmp = (dot[j] - '0')*2 + d;
            d = tmp / 10;
            dot[j] = tmp % 10 + '0';
        }
        ans += d + '0';
    }
    if(suc) {
        cout << ans << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    int n;
    string num;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        cin >> num;
        solve(num);
    }
    return 0;
}


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
    int n;
    scanf("%d", &n);
    
    int sg = 0;
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sg ^= x;
    }
    
    if(sg == 0) {
        cout << "Bob" << endl;
    }
    else {
        cout << "Alice" << endl;
    }
    return 0;
}
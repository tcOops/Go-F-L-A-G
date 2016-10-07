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
const int N = 20010;

int SG[N];
set<int > in;

int main() {
    int n, m;
    
    SG[0] = 0;
    
    /*
    for(int i = 1; i < 100; ++i) {
        in.clear();
        for(int j = 0; j < i; ++j) {
            in.insert(SG[j]);
        }
        
        for(int j = 1; j < i; ++j) {
            in.insert(SG[j] ^ SG[i-j]);
        }
        
        int idx = 0;
        while(in.count(idx) != 0) {
            ++idx;
        }
        
        SG[i] = idx;
    }
    */
    
    for(int i = 1; i < N; ++i) {
        switch (i % 4) {
            case 3:
                SG[i] = i + 1;
                break;
            case 2:
                SG[i] = i;
                break;
            case 1:
                SG[i] = i;
                break;
            case 0:
                SG[i] = i - 1;
                break;
        }
    }
   
    /*
    for(int i = 0 ; i < N; ++i) {
        printf("%d ", SG[i]);
    }
     */
    
    
    scanf("%d", &n);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &m);
        ans ^= SG[m];
    }
    if(!ans) {
        printf("Bob\n");
    }
    else {
        printf("Alice\n");
    }
    return 0;
}
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
const int N = 100010;

struct event {
    int t, type;
    bool operator <(const event & rhs) const {
        return (t < rhs.t) || (t == rhs.t && type > rhs.type);
    }
}events[N<<1];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < (n<<1); i += 2) {
        scanf("%d %d", &events[i].t, &events[i+1].t);
        events[i].type = 1, events[i+1].type = 2;
    }
    
    sort(events, events + (n<<1));
    int ans = 0, cnt = 0;
    for(int i = 0; i < (n<<1); ++i) {
        if(events[i].type == 1) {
            ++cnt;
            if(cnt > ans) {
                ans = cnt;
            }
        }
        else {
            --cnt;
        }
    }
    printf("%d\n", ans);
    return 0;
}




#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;

int edge[N][N];
int cost[N];
struct node {
    int u, d;
    bool operator < (const node &rhs) const {
        return d > rhs.d;
    }
};
priority_queue<node > prim;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &edge[i][j]);
        }
    }
    
    memset(cost, INF, sizeof(cost));
    cost[0] = 0;
    prim.push(node{0, 0});
    
    int ans = 0;
    while(!prim.empty()) {
        node u = prim.top();
        prim.pop();
        
        if(cost[u.u] != u.d) {
            continue;
        }
        
        ans += u.d;
        for(int v = 0; v < n; ++v) {
            if(cost[v] > edge[u.u][v]) {
                cost[v] = edge[u.u][v];
                prim.push(node{v, cost[v]});
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
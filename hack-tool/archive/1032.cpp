#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

struct node {
    int u, d;
    bool operator < (const node &rhs) const {
        return d > rhs.d;
    }
};
vector<node > edge[N];
int cost[N];
bool vis[N];
priority_queue<node > prim;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        edge[x].push_back(node{y, z});
        edge[y].push_back(node{x, z});
    }
    memset(cost, INF, sizeof(cost));
    memset(vis, false, sizeof(vis));
    cost[1] = 0;
    prim.push(node{1, 0});
    
    int ans = 0;
    while(!prim.empty()) {
        node u = prim.top();
        prim.pop();
        
        if(vis[u.u]) {
            continue;
        }
        
        //if(cost[u.u] == u.d) 这种方式只适合dijkstra, 对于prim如果同一条边这样判断可能会加入多次
        //而dijkstra即使加入多次，也没影响(一个算d[i],一个算总的cost)
        
        vis[u.u] = true, ans += u.d;
        for(node v : edge[u.u]) {
            if(cost[v.u] > v.d) {
                cost[v.u] = v.d;
                prim.push(node{v.u, v.d});
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

bool inQ[N];
int d[N];
vector<int > g[N];
queue<int > spfa;

struct node {
    int u, cost;
}edge[1000000*2 + 10];

int main() {
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        edge[i<<1].u = y, edge[i<<1].cost = z;
        g[x].push_back(i<<1);
        edge[i<<1|1].u = x, edge[i<<1|1].cost = z;
        g[y].push_back(i<<1|1);
    }
    
    while(!spfa.empty()) {
        spfa.pop();
    }
    memset(d, INF, sizeof(d));
    memset(inQ, false, sizeof(inQ));
    spfa.push(s);
    d[s] = 0;
    
    while(!spfa.empty()) {
        int u = spfa.front();
        spfa.pop();
        inQ[u] = false;
        
        for(int v : g[u]) {
            node keep = edge[v];
            
            if(d[keep.u] > d[u] + keep.cost) {
                d[keep.u] = d[u] + keep.cost;
                if(!inQ[keep.u]) {
                    spfa.push(keep.u);
                    inQ[keep.u] = true;
                }
            }
        }
    }
    
    printf("%d", d[t]);
    return 0;
}

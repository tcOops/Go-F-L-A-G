#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N = 1010;
const int INF = 0x3f3f3f3f;

int d[N], n, m, s, t;;

struct node {
    int d, u;
    bool operator < (const node &rhs) const {
        return d > rhs.d;
    }
};
priority_queue<node> pq;
int g[N][N];
//vector<node > g[N];

void solve(int s, int e) {
    for(int i = 1; i <= n; ++i) {
        d[i] = INF;
    }
    d[s] = 0;
    pq.push(node{0, s});
    
    while(!pq.empty()) {
        node p = pq.top();
      //  printf("cur : %d\n", p.u);
        pq.pop();
        
        if(d[p.u] != p.d) {
            continue;
        }
        
        if(p.u == e) {
            break;
        }
        
        for(int v = 1; v <= n; ++v) {
            if(v != p.u && d[v] > d[p.u] + g[p.u][v]) {
                d[v] = d[p.u] + g[p.u][v];
                pq.push(node{d[v], v});
            }
        }
    }
    printf("%d\n", d[e]);
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    memset(g, INF, sizeof(g));
    for(int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(z < g[x][y]) {
            g[x][y] = z;
            g[y][x] = z;
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        
    }
    
    solve(s, t);
    return 0;
}
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
typedef long long LL;
const int N = 200010;
const int M = 510;
const long long INF = (long long)1 << 50;

int tot, cnt;
int edges[N], nxt[N];
int head[M];
bool vis[N];

void addEdge(int u, int v) {
    edges[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

bool solve(int p, int fa) {
    ++cnt, vis[p] = true;
    for(int i = head[p]; i; i = nxt[i]) {
        int v = edges[i];
        if(v == fa) {
            continue;
        }
        if(vis[v]) {
            return false;
        }
        solve(v, p);
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        memset(head, 0, sizeof(head));
        memset(vis, false, sizeof(vis));
        
        tot = 0;
        for(int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            addEdge(x, y), addEdge(y, x);
        }
        
        cnt = 0;
        bool suc = solve(1, 0);
        if(!suc || (cnt != n)) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }
    return 0;
}
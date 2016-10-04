#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 1010;

int link[N];
bool vis[N];
vector<int > g[N];

bool find(int u) {
    for(int v : g[u]) {
        if(!vis[v]) {
            vis[v] = true;
            if(link[v] == -1 || find(link[v])) {
                link[v] = u;
                return true;
            }
        }
    }
    
    return false;
}


void solve(int n) {
    int ans = 0;
    memset(link, -1, sizeof(link));
    
    for(int i = 1; i <= n; ++i) {
        memset(vis, false, sizeof(vis));
        if(find(i)) {
            ++ans;
        }
    }
    
    printf("%d\n", ans >> 1);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    solve(n);
    return 0;
}
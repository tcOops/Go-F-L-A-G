#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 10010;

int in[N];
bool vis[N];
vector<int > g[N];

void dfs(int u) {
    vis[u] = true;
    
    for(int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if(!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        in[x]++, in[y]++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    memset(vis, false, sizeof(vis));
    dfs(1);
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            printf("Part\n");
            return 0;
        }
    }
    
    int odd = 0;
    for(int i = 1; i <= n; ++i) {
        if(in[i] & 1) {
            ++odd;
        }
    }
    if(odd == 0 || odd == 2) {
        printf("Full\n");
    }
    else {
        printf("Part\n");
    }
    return 0;
}
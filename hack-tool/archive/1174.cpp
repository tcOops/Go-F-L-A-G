#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100010;

vector<int > g[N];
short vis[N];

bool dfs(int u) {
    vis[u] = -1;
    for(auto v : g[u]) {
        if(vis[v] == -1) {
            return false;
        }
        if(vis[v] == 0) {
            if(!dfs(v)) {
                return false;
            }
        }
    }
    vis[u] = 1;
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m, x, y;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            g[i].clear();
        }
        
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
        }
        
        memset(vis, 0, sizeof(vis));
        bool suc = true;
        for(int i = 0; i < n; ++i) {
            if(vis[i] == 0) {
                if(!dfs(i)){
                    printf("Wrong\n");
                    suc = false;
                    break;
                }
            }
        }
        if(suc) {
            printf("Correct\n");
        }
    }
    return 0;
}
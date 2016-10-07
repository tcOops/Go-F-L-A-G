#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int N = 1010;

int g[N][N];
int stack[N*N];
int cnt = 0;

void dfs(int u, int n) {
    for(int i = 1; i <= n; ++i) {
        if(g[u][i]) {
            --g[u][i];
            --g[i][u];
            dfs(i, n);
        }
    }
    stack[cnt++] = u;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x][y]++;
        g[y][x]++;
    }
    
    cnt = 0;
    dfs(1, n);
    
    for(int i = cnt-1; i >= 0; --i) {
        printf("%d ", stack[i]);
    }
    return 0;
}
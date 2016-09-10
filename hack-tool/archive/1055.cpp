#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define maxab(a, b) ((a) > (b) ? (a) : (b))

vector<int > g[110];
int score[110];
int dp[110][110];

void solve(int u, int fa, int m) {
    for(int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if(v == fa) {
            continue;
        }
        
        solve(v, u, m);
        for(int j = m; j >= 2; --j) {
            for(int k = 1; k < j; ++k) {
                dp[u][j] = maxab(dp[v][k] + dp[u][j-k], dp[u][j]);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &dp[i][1]);
    }
    for(int i = 0; i < n-1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    solve(1, -1, m);
    printf("%d\n", dp[1][m]);
    return 0;
}



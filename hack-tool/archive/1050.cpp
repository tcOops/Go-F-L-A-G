#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 100010;

vector<int > g[N];
int ans = 0;

int solve(int u, int fa) {
    int res1 = 0, res2 = 0;
    for(int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if(v == fa) continue;
        
        int dist = solve(v, u);
        if(dist > res1) {
            res2 = res1;
            res1 = dist;
        }
        else if(dist > res2) {
            res2 = dist;
        }
    }
    
    int ret = 1 + res1 + res2;
    if(ret > ans) {
        ans = ret;
    }
    
    if(res1 > res2) {
        return 1 + res1;
    }
    return 1 + res2;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n-1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    solve(1, -1);
    printf("%d\n", ans-1);
    return 0;
}
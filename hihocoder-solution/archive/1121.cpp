//Bipartite graph decision
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 10010;

int col[N], cnt;
vector<int > g[N];

bool go(int u, int color) {
    col[u] = color;
    
    for(int v : g[u]) {
        if(col[v] == 0) {
            if(!go(v, col[u] ^ 3)) {
                return false;
            }
        }
        else if(col[v] == col[u]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int T, n, m;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            g[i].clear();
        }
        for(int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        memset(col, 0, sizeof(col));
        cnt = 0;
        string ans = "Correct";
        for(int i = 1; i <= n; ++i) {
            if(col[i] == 0) {
                if(!go(i, 1)) {
                    ans = "Wrong";
                    break;
                }
            }
        }
       // cout << ans << endl;
        printf("%s\n", ans.c_str());
    }
    return 0;
}
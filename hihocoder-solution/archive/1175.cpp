#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N = 100010;
const int MOD = 142857;

vector<int > g[N];
queue<int > topo;
int in[N], virus[N];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    memset(virus, 0, sizeof(virus));
    for(int i = 0; i < k; ++i) {
        int pos;
        scanf("%d", &pos);
        virus[pos]++;
    }
    for(int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        in[y]++;
    }
    
    for(int i = 1; i <= n; ++i) {
        if(in[i] == 0) {
            topo.push(i);
        }
    }

 //   int cnt = 0;
    while(!topo.empty()) {
        int p = topo.front();
        topo.pop();
        for(int v : g[p]) {
            in[v]--;
            virus[v] += virus[p];
            virus[v] %= MOD;
            if(in[v] == 0) {
                topo.push(v);
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = (ans + virus[i]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define minab(a, b) ((a) < (b) ? (a) : (b))
const int N = 101;
const int INF = 0x3f3f3f3f;

int edge[N][N];
int d[N][N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    memset(d, INF, sizeof(d));
    for(int i = 1; i <= n; ++i) {
        d[i][i] = 0;
    }
    
    for(int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(d[x][y] > z) {
            d[x][y] = z;
            d[y][x] = z;
        }
    }
    
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = minab(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            printf("%d ", d[i][j]);
        }
        puts("");
    }
    return 0;
}
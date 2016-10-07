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
const int N = 110;
const int MOD = 1e9 + 7;

bool vis[N][N];
int fx[4] = {0, 0, 1, -1};
int fy[4] = {1, -1, 0, 0};
int m, n;
int a[N][N], minx, maxx, miny, maxy;
int ans = 0;

int cal(int x) {
    int ret = 0;
    while(x) {
        ++ret;
        x = x & (x-1);
    }
    return ret;
}

void solve(int x, int y) {
    //   printf("%d %d\n", x, y);
    vis[x][y] = true;
    
    for(int i = 0; i < 4; ++i) {
        int newx = x + fx[i];
        int newy = y + fy[i];
        if(newx < 0 || newx >= m || newy < 0 || newy >= n) {
            ++ans;
            continue;
        }
        if(vis[newx][newy]) {
            continue;
        }
        if((a[newx][newy] != a[x][y])) {
            ++ans;
            continue;
        }
        solve(newx, newy);
    }
}

int main() {
    int x, y;
    scanf("%d %d %d %d", &m, &n, &x, &y);
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    
    memset(vis, 0, sizeof(vis));
    minx = 1e9, maxx = -1, miny = 1e9, maxy = -1;
    ans = 0;
    solve(x, y);
    printf("%d\n", ans);
    // printf("%d\n", (maxx - minx + maxy - miny + 2) * 2);
    return 0;
}
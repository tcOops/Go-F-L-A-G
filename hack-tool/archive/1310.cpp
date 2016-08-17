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
const int N = 51;
typedef pair<int, int> pii;

map<int, int> mp_cnt;
map<string, int> mp_shape;
char pic[N][N];
queue<pair<int, int> > q;
int fx[4] = {0, 0, 1, -1};
int fy[4] = {1, -1, 0, 0};
int n, m;

pair<int, string> solve(int x, int y) {
    while(!q.empty()) {
        q.pop();
    }
    q.push(make_pair(x, y));
    pic[x][y] = '.';
    
    string shapes = "";
    int cnt = 0;
    while(!q.empty()) {
        pii p = q.front();
        q.pop(), ++cnt;
      //  pic[p.first][p.second] = '.';
        
        string shape = "";
        for(int i = 0; i < 4; ++i) {
            int newx = p.first + fx[i];
            int newy = p.second + fy[i];
            if(newx < 0 || newx >= m || newy < 0 || newy >= n) {
                shape += "0";
                continue;
            }
            if(pic[newx][newy] == '.') {
                shape += "0";
                continue;
            }
            
            pic[newx][newy] = '.';
            q.push(make_pair(newx, newy));
            shape += "1";
        }
        shapes += shape;
    }
    return make_pair(cnt, shapes);
}

int main() {
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; ++i) {
        scanf("%s", pic[i]);
    }
    
    int ans = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(pic[i][j] == '#') {
                ++ans;
                pair<int, string> ret = solve(i, j);
                mp_cnt[ret.first]++;
                mp_shape[ret.second]++;
            }
        }
    }
    printf("%d %d %d\n", ans, (int)mp_cnt.size(), (int)mp_shape.size());
    return 0;
}


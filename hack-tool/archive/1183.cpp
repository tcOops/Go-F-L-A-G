// Author: RejudgeX
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
//#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll MOD = 1000000007;
const int N = 20010;

int dfn[N], low[N];
int num, cnt;
int head[N], nxt[N];
int edges[N<<1];
vector<int > g[N];
bool isCut[N];

vector<pair<int, int> > cutEdges;
vector<int > cutPoints;

void addEdge(int x, int y) {
    edges[++num] = y;
    nxt[num] = head[x], head[x] = num;
}

int dfs(int u, int fa) {
    int lowu = dfn[u] = ++cnt;
    int childCnt = 0;
    bool ff = false;
    
    for(auto v : g[u]) {
        if(!dfn[v]) {
            ++childCnt;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if(lowv >= dfn[u]) {
                ff = true;
            }
            if(lowv > dfn[u]) {
                cutEdges.push_back(make_pair(min(u, v), max(u, v)));
            }
        }
        else if(dfn[v] < dfn[u] && v != fa) {
            lowu = min(lowu, dfn[v]);
        }
    }
    
    //special -> Root
    if((fa < 0 && childCnt > 1) || (fa >= 0 && ff)) {
       // isCut[u] = true;
        cutPoints.push_back(u);
    }
    
    low[u] = lowu;
    return lowu;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    num = cnt = 0;
    for(int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
     //   addEdge(x, y), addEdge(y, x);
        g[x].push_back(y), g[y].push_back(x);
    }
    
    dfs(1, -1);
    sort(cutEdges.begin(), cutEdges.end());
    sort(cutPoints.begin(), cutPoints.end());
    
    if(cutPoints.size() == 0) {
        puts("Null");
    }
    else {
        printf("%d", cutPoints[0]);
        for(int i = 1; i < cutPoints.size(); ++i) {
            printf(" %d", cutPoints[i]);
        }
        puts("");
    }
    
    for(int i = 0; i < cutEdges.size(); ++i) {
        printf("%d %d\n", cutEdges[i].first, cutEdges[i].second);
    }
    return 0;
}




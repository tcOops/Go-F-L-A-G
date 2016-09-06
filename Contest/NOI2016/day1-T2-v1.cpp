

// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//NOI2016 -> Day1 -> T2

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
const ll mod = 1000000007;

ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

inline void gn(long long &x){
    int sg=1;
    char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}

inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}

const int N = 1000010;
int fx[4] = {0, 0, 1, -1};
int fy[4] = {1, -1, 0, 0};

int ffx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int ffy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

bool vis[N];
int maze[N], dfn[N], low[N], head[N], nxt[N];
int n, m, c;
set<pair<int, int> > st;
int edges[N<<2], num, cnt;
vector<pair<int, int> > barriers;
bool once;

void addEdge(int x, int y) {
    edges[++num] = y;
    nxt[num] = head[x], head[x] = num;
}

void dfs(int x, int y) {
    vis[x*m+y] = true;
    for(int i = 0; i < 4; ++i) {
        int newx = x + fx[i], newy = y + fy[i];
        if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
        if(vis[newx*m+newy] || maze[newx*m+newy]) continue;
        dfs(newx, newy);
    }
}

int tarjan(int u, int fa) {
    low[u] = dfn[u] = ++cnt;
    int childCnt = 0;
    bool ff = false;

    for(int i = head[u]; i; i = nxt[i]) {
        int v = edges[i];
        if(!dfn[v]) {
            ++childCnt;
            int lowv = tarjan(v, u);
            low[u] = min(low[u], lowv);
            if(lowv >= dfn[u]) {
                ff = true;
            }
        }
        else if(v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if((fa < 0 && childCnt > 1) || (fa >= 0 && ff)) {
        once = true;
    }
    return low[u];
}

int main() {
    int T; gn(T);
    while(T--) {
        gn(n); gn(m); gn(c);

        barriers.clear();
        memset(maze, false, sizeof(maze));
        for(int i = 0; i < c; ++i) {
            int x, y;
            gn(x); gn(y);
            --x, --y;
            barriers.push_back(make_pair(x, y));
            maze[x*m+y] = true;
        }

        //No solution
        if(n*m - c < 2) {
            printf("-1\n");
            continue;
        }
        if(n*m - c == 2) {
            vector<pair<int, int> > land;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(!maze[i*m+j]) {
                        land.push_back(make_pair(i, j));
                    }
                }
            }
            int diffx = abs(land[0].fi - land[1].fi);
            int diffy = abs(land[0].se - land[1].se);
            if(diffx + diffy == 1) {
                printf("-1\n");
                continue;
            }
        }

        memset(vis, false, sizeof(vis));

        bool sta = false;
        for(int i = 0; i < n && !sta; ++i) {
            for(int j = 0; j < m; ++j) {
                if(!maze[i*m+j]) {
                    dfs(i, j);
                    sta = true;
                    break;
                }
            }
        }

        bool suc = true;
        for(int i = 0; i < n && suc; ++i) {
            for(int j = 0; j < m; ++j) {
                if((!maze[i*m+j]) && (!vis[i*m+j])) {
                    suc = false;
                    break;
                }
            }
        }
        if(!suc) {
            printf("0\n");
            continue;
        }

        //Ans = 1
        once = false;
        if(n == 1 || m == 1) {
            once = true;
        }
        else if(c == 0) {
            once = false;
        }
        else if(c == 1) {
            int dist1, dist2, dist3, dist4;
            dist1 = barriers[0].fi + barriers[0].se;
            dist2 = barriers[0].fi + m - 1 - barriers[0].se;
            dist3 = n - 1 - barriers[0].fi + barriers[0].se;
            dist4 = n - 1 - barriers[0].fi + m - 1 - barriers[0].se;
            if(dist1 == 1 || dist2 == 1 || dist3 == 1 || dist4 == 1) {
                once = true;
            }
        }
        else {
            memset(head, 0, sizeof(head));
            memset(nxt, 0, sizeof(nxt));
            memset(dfn, 0, sizeof(dfn));
            num = 0, cnt = 0;
            for(int p = 0; p < n; ++p){
                for(int q = 0; q < m; ++q) {
                    if(!maze[p*m+q]) {
                        for(int k = 0; k < 4; ++k) {
                            int newx = p + fx[k];
                            int newy = q + fy[k];
                            if(newx < 0 || newx >= n || newy < 0 || newy >= m) {
                                continue;
                            }
                            if(maze[newx*m + newy]) {
                                continue;
                            }
                            addEdge(p*m+q, newx*m+newy);
                        }
                    }
                }
            }

            bool isTarjan = false;
            for(int p = 0; p < n && !isTarjan; ++p) {
                for(int q = 0; q < m; ++q) {
                    if(!maze[p*m+q]) {
                        tarjan(p*m+q, -1);
                        isTarjan = true;
                        break;
                    }
                }
            }
        }

        if(once) {
            printf("1\n");
        }
        else {
            printf("2\n");
        }
    }
    return 0;
}

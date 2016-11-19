//挑战程序设计竞赛－系列

// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//2008 Round 1A C
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

const int N = 110;

int link[N*N];
bool vis[N*N];
vector<int > g[N*N];
int n, m, cnt;
char s[N][N];
int dx[4] = {0, 0, -1, -1};
int dy[4] = {-1, 1, -1, 1};

bool find(int u) {
    for(int v : g[u]) {
        if(!vis[v]) {
            vis[v] = true;
            if(link[v] == -1 || find(link[v])) {
                link[v] = u;
                return true;
            }
        }
    }

    return false;
}


void solve(int nn) {
    int ans = 0;
    memset(link, -1, sizeof(link));

    for(int i = 0; i < nn; ++i) {
        int dx = i / m, dy = i % m;
        if((dy & 1) && (s[dx][dy] == '.')) {
          memset(vis, false, sizeof(vis));
          if(find(i)) {
              ++ans;
          }
        }
    }

    printf("%d\n", cnt - ans);
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, cases = 1; gn(T);
  while(T--) {
    gn(n); gn(m);
    for(int i = 0; i < n; ++i) {
      scanf("%s", s[i]);
    }
    for(int i = 0; i < n*m; ++i) {
      g[i].clear();
    }

    cnt = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(s[i][j] == '.') {
          ++cnt;
          for(int k = 0; k < 4; ++k) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
              continue;
            }
            if(s[nx][ny] == 'x') {
              continue;
            }
            g[i*m+j].push_back(nx*m+ny);
            g[nx*m+ny].push_back(i*m+j);
          }
        }
      }
    }
    printf("Case #%d: ", cases++);
    solve(n*m);
  }
  return 0;
}

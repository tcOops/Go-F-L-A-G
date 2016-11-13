//APAC2017 Round C
//AC
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
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll MOD = 1000000007;

ll powMOD(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
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

/*
const int N = 21;
char maze[N][N];
int vis[N][N];
int fx[4] = {0, 0, 1, -1};
int fy[4] = {1, -1, 0, 0};
int R, C, RS, CS, S;
double Q, P;
double ans;

void solve(int x, int y, double sum, int cnt) {
  if(cnt == S) {
    if(sum > ans) {
      ans = sum;
    }
    return ;
  }

  for(int i = 0; i < 4; ++i) {
    int dx = x + fx[i];
    int dy = y + fy[i];
    if(dx < 0 || dx >= R || dy < 0 || dy >= C) {
      continue;
    }

    double fac = Q;
    if(maze[dx][dy] == 'A') {
      fac = P;
    }

    double res = 1.0;
    for(int i = 1; i <= vis[dx][dy]; ++i) {
      res = (1 - fac) * res;
    }
  //  printf("%.7lf\n", res);
    vis[dx][dy]++;
    solve(dx, dy, sum + res*fac, cnt+1);
    vis[dx][dy]--;
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, cases = 1; gn(T);
  char ss[N<<1];
  while(T--) {
    scanf("%d%d%d%d%d", &R, &C, &RS, &CS, &S);
    scanf("%lf%lf", &P, &Q);
    getchar();
    for(int i = 0; i < R; ++i) {
      gets(ss);
      for(int j = 0; j < C; ++j) {
        maze[i][j] = ss[j<<1];
      }
    }
    memset(vis, 0, sizeof(vis));
    ans = 0.0;
    solve(RS, CS, 0.0, 0);
    printf("Case #%d: %.7lf\n", cases++, ans);
  }
  return 0;
}
*/

/*
const int N = 3010;
int dp[N][N];
int R, C, K;
set<pair<int, int> > block;

int main() {
  int T, cases = 1;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d %d", &R, &C, &K);
    block.clear();
    for(int i = 0; i < K; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      ++x, ++y;
      block.insert(make_pair(x, y));
    }

    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for(int i = 1; i <= R; ++i) {
      if(block.find(make_pair(i, 1)) == block.end()) {
        dp[i][1] = 1;
        ++ans;
      }
      else {
        dp[i][1] = 0;
      }
    }
    for(int i = 1; i <= C; ++i) {
      if(block.find(make_pair(1, i)) == block.end()) {
        dp[1][i] = 1;
        ++ans;
      }
      else {
        dp[1][i] = 0;
      }
    }

    for(int i = 2; i <= R; ++i) {
      for(int j = 2; j <= C; ++j) {
        if(block.find(make_pair(i, j)) == block.end()) {
          dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
        }
        else {
          dp[i][j] = 0;
        }
        ans += dp[i][j];
      }
    }
    printf("Case #%d: %d\n", cases++, ans);
  }
  return 0;
}
*/

/*
const int N = 10010;
int in[N];
vector<int > g[N];
char st[N];
map<string, int> mp;
string tmp, res;
queue<int > que;
bool def[N];

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, cases = 1;
  scanf("%d", &T);
  while(T--) {
    int n, cnt = 0;
    scanf("%d", &n);
    mp.clear();
    memset(in, 0, sizeof(in));
    memset(def, 0, sizeof(def));
    while(!que.empty()) {
      que.pop();
    }
    for(int i = 0; i < n; ++i) {
      scanf("%s", st);
      tmp = "";
      int j = 0, src, dep;
      for(; st[j] != '='; ++j) {
        tmp += st[j];
      }
      while(st[j] != '(') {
        ++j;
      }

      if(mp.find(tmp) == mp.end()) {
        mp[tmp] = cnt++;
        g[cnt-1].clear();
      }
      src = mp[tmp];
      def[src] = true;
      j += 1;
      while(st[j] != ')') {
        int k = j;
        res = "";
        while(st[k] != ')' && st[k] != ',') {
          res += st[k++];
        }
        if(mp.find(res) == mp.end()) {
          mp[res] = cnt++;
          g[cnt-1].clear();
        }
        dep = mp[res];
        in[src]++, g[dep].push_back(src);
        if(st[k] == ')') {
          break;
        }
        j = k + 1;
      }
    }

    for(int i = 0; i < cnt; ++i) {
    //  printf("%d ", in[i]);
      if(in[i] == 0 && def[i]) {
        que.push(i);
      }
    }

    int num = 0;
    while(!que.empty()) {
      int p = que.front();
      que.pop(), ++num;
      for(auto v : g[p]) {
        in[v]--;
        if(in[v] == 0) {
          que.push(v);
        }
      }
    }
    if(num == cnt) {
      printf("Case #%d: GOOD\n", cases++);
    }
    else {
      printf("Case #%d: BAD\n", cases++);
    }
  }
  return 0;
}
*/

<<<<<<< HEAD
=======
/*
>>>>>>> 27ac5675e9532836194aafe4bb9727cb6f46c673
const int N = 2010;
int dp[N][N];
int n;
struct node {
  int a, d;
  int idx;
}o[N], b[N], c[N];

bool cmp1(const node &a, const node &b) {
  return a.a < b.a;
}

bool cmp2(const node &a, const node &b) {
  return a.d < b.d;
}

int tag = 0;
int solve(int u, int v) {
  if(dp[u][v] != -1e9) {
    return dp[u][v];
  }
  bool sta = false;
  int ans = -1e9;
  for(int i = n - 1; i >= 0; --i) {
    if(b[i].a <= o[u].a) {
      break;
    }
    sta = true;
    int nextv = v;
    if(b[i].d > o[v].d) {
      nextv = b[i].idx;
    }
    int res = solve(b[i].idx, nextv);
    if(1 - res > ans) {
      ans = 1 - res;
    }
  }
  for(int i = n - 1; i >= 0; --i) {
    if(c[i].d <= o[v].d) {
      break;
    }
    sta = true;
    int nextu = u;
    if(c[i].a > o[u].a) {
      nextu = c[i].idx;
    }
    int res = solve(nextu, c[i].idx);
    if(1 - res > ans) {
      ans = 1 - res;
    }
  }
  if(!sta) {
    return (dp[u][v] = 0);
  }
  else {
    return (dp[u][v] = ans);
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, cases = 1;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
      scanf("%d %d", &o[i].a, &o[i].d);
      o[i].idx = i;
      b[i].a = c[i].a = o[i].a;
      b[i].d = c[i].d = o[i].d;
      b[i].idx = c[i].idx = o[i].idx;
    }

    sort(b, b+n, cmp1);
    sort(c, c+n, cmp2);
  //  memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        dp[i][j] = -1e9;
      }
    }
    bool suc = false;
    for(int i = 0; i < n; ++i) {
      int res = solve(i, i);
      if(1 - res > 0) {
        suc = true;
      }
    }
    printf("Case #%d: %s\n", cases++, suc ? "YES" : "NO");
  }
  return 0;
}
*/

const int N = 4010;
int a[N], d[N];

bool solve(int cnt) {
  if(cnt == 0) {
    return 0;
  }

  int mx = 0, my = 0;
  for(int i = 0; i < cnt; ++i) {
    if(a[i] > mx) {
      mx = a[i];
    }
    if(d[i] > my) {
      my = d[i];
    }
  }

  int nxt = 0;
  for(int i = 0; i < cnt; ++i) {
    if(a[i] < mx && d[i] < my) {
      a[nxt] = a[i], d[nxt++] = d[i];
    }
    else if(a[i] == mx && d[i] == my) {
      return true;
    }
  }
  return solve(nxt);
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, cases = 1;
  scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
      scanf("%d %d", &a[i], &d[i]);
    }
    if(solve(n)) {
      printf("Case #%d: YES\n", cases++);
    }
    else {
      printf("Case #%d: NO\n", cases++);
    }
  }
  return 0;
}

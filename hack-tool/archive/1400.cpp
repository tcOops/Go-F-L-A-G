//AC

// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//
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
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
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

const int N = 100010;
const int INF = 0x3f3f3f3f;
bool vis[30][30];
int pos[30], dp[N];
char s[N];

int main() {
  int n, m; gn(n);
  scanf("%s", s);
  gn(m);
  char fbd[10];

  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < m; ++i) {
    scanf("%s", fbd);
    vis[fbd[0]-'a'][fbd[1]-'a'] = 1;
    vis[fbd[1]-'a'][fbd[0]-'a'] = 1;
  }

  memset(pos, -1, sizeof(pos));

  for(int i = 0; i < n; ++i) {
    dp[i] = i;
    int cur = s[i] - 'a';
    for(int j = 0; j < 26; ++j) {
      if(vis[cur][j] || pos[j] == -1) continue;
      dp[i] = min(dp[i], dp[pos[j]] + (i - pos[j] - 1));
    }
    if(pos[cur] == -1 || (dp[pos[cur]] + i - pos[cur]) > dp[i]) {
      pos[cur] = i;
    }
  }

  int ans = INF;
  for(int i = 0; i < n; ++i) {
  //  printf("%d ", dp[i]);
    if(dp[i] + (n - i - 1) < ans) {
      ans = dp[i] + n - i - 1;
    }
  }
  cout << ans << endl;
  return 0;
}

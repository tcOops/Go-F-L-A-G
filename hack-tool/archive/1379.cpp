// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//Tree Dp
//考虑当前节点与父节点之间是否有操作的关系
//dp[i][2]->表示未进行操作, dp[i][0]->进行操作1, dp[i][1]->进行操作了2
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
const int N = 310;
int dist[N][N];
bool conn[N][N];

void solve(int n) {
  memset(conn, true, sizeof(conn));
  for(int k = 0; k < n; ++k) {
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i == k || j == k) continue;
        if(dist[i][k] + dist[k][j] == dist[i][j]) {
          conn[i][j] = false;
        }
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      if(conn[i][j]) {
        ++ans;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  int n; gn(n);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      gn(dist[i][j]);
    }
  }
  solve(n);
  return 0;
}

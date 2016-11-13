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
#include <bitset>
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

const int N = 1e6 + 10;
int dp[N];
int x, k, t;
struct node {
  int idx, val;
} que[N];

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d %d", &x, &k, &t);
    dp[1] = 0;
    int head = 0, tail = 0;
    que[tail++] = node {1, 0};
    for(int i = 2; i <= x; ++i) {
      while(tail > head && i - que[head].idx > t) {
        ++head;
      }
      dp[i] = 1e9;
      if(tail != head) dp[i] = que[head].val + 1;
      if(i % k == 0 && k != 1) {
        dp[i] = min(dp[i], dp[i/k] + 1);
      }
      while(tail > head && dp[i] <= que[tail-1].val) {
        --tail;
      }
      que[tail++] = node {i, dp[i]};
    }
    printf("%d%s", dp[x], T == 0 ? "" : "\n");
  }
  cout << endl;
}

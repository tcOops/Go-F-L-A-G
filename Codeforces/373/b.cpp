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

string col;
const int N = 100010;
int dp[N][2];

int main() {
  int n; gn(n);
  cin >> col;
  int cnt1 = 0, cnt2 = 0;
  for(int i = 0; i < n; ++i) {
    if((i & 1) && (col[i] != 'r')) {
      ++cnt1;
    }
    if(!(i & 1) && (col[i] != 'b')) {
      ++cnt2;
    }
  }
  int ans = max(cnt1, cnt2);

  cnt1 = cnt2 = 0;
  for(int i = 0; i < n; ++i) {
    if((i & 1) && (col[i] != 'b')) {
      ++cnt1;
    }
    if(!(i & 1) && (col[i] != 'r')) {
      ++cnt2;
    }
  }
  if(max(cnt1, cnt2) < ans) {
    ans = max(cnt1, cnt2);
  }
  cout << ans << endl;
  return 0;
}

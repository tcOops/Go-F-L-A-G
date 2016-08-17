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

const int N = 21;
int h[21];
vector<int > y, yp;
int q[110][4], ans[110];

int main() {
  int n, m;
  gn(n); gn(m);
  h[1] = 0, h[2] = 1, h[3] = 2;
  for(int i = 4; i < N; ++i) {
    h[i] = h[i-1] << 1 | 1;
  }

  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < 4; ++j) {
      gn(q[i][j]);
    }
  }


  int posx = 0;
  yp.push_back(0);
  for(int i = 1; i < n; ++i) {
    posx = posx + h[n+1-i] + 1;
    y.clear();
    for(int j = 0; j < yp.size(); ++j) {
      y.push_back(yp[j] - h[n+1-i] - 1);
      y.push_back(yp[j] + h[n+1-i] + 1);
    }

    for(int j = 0; j < m; ++j) {
      if(q[j][0] <= posx && posx <= q[j][2]) {
        int l = lower_bound(y.begin(), y.end(), q[j][1]) - y.begin();
        int r = upper_bound(y.begin(), y.end(), q[j][3]) - y.begin();
        ans[j] += r - l;
      }
    }

    yp.swap(y);
  }

  for(int i = 0; i < m; ++i) {
    if(0 >= q[i][0] && q[i][2] >= 0 && 0 >= q[i][1] && q[i][3] >= 0) {
      ++ans[i];
    }
    cout << ans[i] << endl;
  }
  return 0;
}

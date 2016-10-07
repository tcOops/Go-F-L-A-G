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
const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;

int h[N];
int n, m, L;

bool check(int x) {
  for(int i = 1; i <= n; ++i) {
    bool suc = true;

    int left = m;
    for(int j = i; j < i + n && suc;) {
      if(h[j] >= x) {
        ++j;
        continue;
      }
      if(left == 0) {
        suc = false;
        break;
      }
      j += L;
      --left;
    }
    if(suc) {
      return true;
    }
  }
  return false;
}

int main() {
  gn(n); gn(m); gn(L);
  int l = INF, r = 0;
  for(int i = 1; i <= n; ++i) {
    gn(h[i]);
    h[i+n] = h[i];
    if(h[i] > r) {
      r = h[i];
    }
    if(h[i] < l) {
      l = h[i];
    }
  }

  while(l < r) {
//    cout << l << " " << r << endl;
    int mid = (l + r + 1) >> 1;
    if(check(mid)) {
      l = mid;
    }
    else {
      r = mid - 1;
    }
  }
  printf("%d\n", l);
  return 0;
}

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

string a;
bool solve(int s, int e) {
  if(s == e) {
    return true;
  }

  for(int i = s; i < e; ++i) {
    bool suc1 = true;
    for(int j = s; j <= i && suc1; ++j) {
      for(int k = i + 1; k <= e; ++k) {
        if(a[j] > a[k]) {
          suc1 = false;
          break;
        }
      }
    }

    bool suc2 = true;
    for(int j = s; j <= i && suc2; ++j) {
      for(int k = i + 1; k <= e; ++k) {
        if(a[j] < a[k]) {
          suc2 = false;
          break;
        }
      }
    }

    if(!suc1 && !suc2) continue;
    if(solve(s, i) && solve(i+1, e)) {
      return true;
    }
  }
  return false;
}

int main() {
  while(cin >> a) {
    if(solve(0, 9)) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

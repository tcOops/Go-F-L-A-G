//AC
<<<<<<< HEAD
=======

>>>>>>> 14b5f2635ab86a03a2ea4b904f198a605128c086
// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」


<<<<<<< HEAD
//1002
=======
>>>>>>> 14b5f2635ab86a03a2ea4b904f198a605128c086
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
<<<<<<< HEAD
#include <stack>
=======
>>>>>>> 14b5f2635ab86a03a2ea4b904f198a605128c086
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
<<<<<<< HEAD
const ll mod = 1000000007;

ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
=======
const ll MOD = 1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
>>>>>>> 14b5f2635ab86a03a2ea4b904f198a605128c086
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

<<<<<<< HEAD
const int N = 100010;
int a[N], r[N];

int main() {
  int T, n;
  gn(T);
  while(T--) {
    gn(n);
    for(int i = 1; i <= n; ++i) {
      gn(a[i]);
    }

    /*
    r[n] = n + 1;
    for(int i = n - 1; i >= 1; --i) {
      int beg = i + 1;
      while(beg <= n && a[beg] > a[i]) {
        beg = r[beg];
      }
      r[i] = beg;
    }
    */

    //这边可以用单调栈的方式求r
    stack<int > st;
    for(int i = 1; i <= n; ++i) {
      r[i] = n + 1;
      while(!st.empty() && a[i] <= a[st.top()]) {
        r[st.top()] = i;
        st.pop();
      }
      st.push(i);
    }

    int m; gn(m);
    for(int i = 1; i <= m; ++i) {
      int x, y;
      gn(x); gn(y);

      int mod = a[x], beg = x;
      while(beg <= y) {
        beg = r[beg];
        while(beg <= y && a[beg] > mod) {
          beg = r[beg];
        }
        if(beg > y) break;
        mod = mod % a[beg];
      }
      cout << mod << endl;
    }

  }
  return 0;
=======
int main() {
  int 
>>>>>>> 14b5f2635ab86a03a2ea4b904f198a605128c086
}

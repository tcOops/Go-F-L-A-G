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

const int N = 310;
int a[N];
set<int > st;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int main() {
  int T; gn(T);
  while(T--) {
    int n; gn(n);
    for(int i = 1; i <= n; ++i) {
      gn(a[i]);
    }

    st.clear();
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j < i; ++j) {
        st.insert(gcd(a[i], a[j]));
      }
    }
    bool flag = false;
    for(set<int >::iterator it = st.begin(); it != st.end(); ++it) {
      if(flag) {
        printf(" ");
      }
      else {
        flag = true;
      }
      printf("%d", *it);
    }
    cout << endl;
  }
  return 0;
}

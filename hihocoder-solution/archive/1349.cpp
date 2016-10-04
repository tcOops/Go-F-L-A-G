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

int main() {
//  #define REJUDGEX
  #ifndef REJUDGEX
  //  freopen("/home/rejudgex/Go_Google/Mithril/input", "r", stdin);
  //  freopen("/home/rejudgex/Go_Google/Mithril/output", "w", stdout);
  #endif

  long long n;
  gn(n); ++n;

  if(n <= 10) {
    cout << n - 1 << endl;
  }
  else {
    long long base = 10, len = 2;
    long long sum = 10;
    while(sum + 9*base*len < n) {
      sum += 9*base*len;
      base *= 10, ++len;
    }
    n -= sum;

    long long dig, num;
    if(n % len == 0) {
      dig = len;
      num = base + n / len - 1;
    }
    else {
      dig = n % len;
      num = base + n / len;
    }
   // cout << n << " " << num << " " << dig << endl;
    vector<int > digs;
    while(num) {
      digs.push_back(num % 10);
      num /= 10;
    }
    cout << digs[digs.size() - dig] << endl;
  }
  return 0;
}

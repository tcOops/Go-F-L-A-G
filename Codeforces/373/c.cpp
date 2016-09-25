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

int main() {
  int n, k;
  gn(n); gn(k);
  string num;
  cin >> num;
  int idx = 0, d = 0;
  int flag;
  while(num[idx] != '.') {
    ++idx;
  }
  flag = idx;
  ++idx;
  while(idx < n && num[idx] < '5') {
    ++idx;
  }

  int flag1 = idx;
  if(idx != n) {
    while(k) {
      if(num[idx] >= '5') {
        num[idx] = '0';
        --idx;
        while(idx > flag) {
          if(num[idx] == '9') {
            num[idx] = '0';
            --idx;
          }
          else {
            num[idx] += 1;
            break;
          }
        }
        if(idx == flag) {
          d = 1;
          break;
        }
      }
      else {
        break;
      }
      --k;
    }
  }

  if(d == 1) {
    vector<int > res;
    for(int i = flag - 1; i >= 0; --i) {
      if(num[i] - '0' + d < 10) {
        res.push_back(num[i] -'0' + d);
        d = 0;
      }
      else {
        res.push_back(0);
        d = 1;
      }
    }
    if(d == 1) {
      res.push_back(1);
    }
    for(int i = res.size() - 1; i >= 0; --i) {
      printf("%d", res[i]);
    }
  }
  else {
    for(int i = 0; i < flag; ++i) {
      printf("%c", num[i]);
    }
  }

  bool flag2 = false;
  for(int i = flag + 1; i < flag1; ++i) {
    if(num[i] != '0') {
      flag2 = true;
      break;
    }
  }
  if(flag2) {
    int j = flag1 - 1;
    while(j > flag && num[j] == '0') {
      --j;
    }
    for(int i = flag; i <= j; ++i) {
      printf("%c", num[i]);
    }
  }
  cout << endl;
  return 0;
}

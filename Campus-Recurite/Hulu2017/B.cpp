//AC
// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//67%　points

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

struct param {
  string name;
  int x, y, z;
  vector<string > val;
  bool operator <(const param & rhs) const {
    return name < rhs.name;
  };
}p[10];
vector<string > ans;

bool cmp(string a, string b) {
  return a < b;
}
int n;

void dfs(int s, int k, string cur, bool flag) {
  if(k == n) {
    ans.push_back(cur);
    return ;
  }
  if(s & (1<<k)) {
    string res = "";
    if(p[k].y == 0) {
      if(p[k].z == 1) {
        for(int j = 0; j < p[k].val.size(); ++j) {
          res = p[k].name + "=-" + p[k].val[j];
          if(!flag) {
            res = "&" + res;
          }
          dfs(s, k+1, cur + res, false);
        }
      }
      for(int j = 0; j < p[k].val.size(); ++j) {
        res = p[k].name + "=" + p[k].val[j];
        if(!flag) {
          res = "&" + res;
        }
        dfs(s, k+1, cur + res, false);
      }
      return ;
    }

    for(int j = 1; j < (1<<p[k].val.size()); ++j) {
      vector<int > tmp;
      for(int t = 0; t < p[k].val.size(); ++t) {
        if((1<<t) & j) {
          tmp.push_back(t);
        }
      }
      if(p[k].z == 1) {
        for(int t = 0; t < (1<<tmp.size()); ++t) {
          string res = "";
          for(int q = 0; q < tmp.size(); ++q) {
            if(q > 0) {
              res += ",";
            }
            if((1<<q) & t) {
              res += "-" + p[k].val[tmp[q]];
            }
            else {
              res += p[k].val[tmp[q]];
            }
          }
          res = p[k].name + "=" + res;
          if(!flag) {
            res = "&" + res;
          }
          dfs(s, k+1, cur + res, false);
        }
      }
      else {
        string res = "";
        for(int q = 0; q < tmp.size(); ++q) {
          if(q > 0) {
            res += ",";
          }
          res += p[k].val[tmp[q]];
        }
        res = p[k].name + "=" + res;
        if(!flag) {
          res = "&" + res;
        }
        dfs(s, k+1, cur + res, false);
      }
    }
  }
  else {
    dfs(s, k+1, cur, flag);
  }
}

int main() {
  gn(n);
  for(int i = 0; i < n; ++i) {
    cin >> p[i].name;
    gn(p[i].x); gn(p[i].y); gn(p[i].z);
    string vals, res;
    cin >> vals;
    for(int idx = 0; idx < vals.size();) {
      int j = idx;
      res = "";
      while(j < vals.size() && vals[j] != ',') {
        res += vals[j++];
      }
      p[i].val.push_back(res);
      sort(p[i].val.begin(), p[i].val.end(), cmp);
      idx = j; ++idx;
    }
  }

  sort(p, p + n);
  for(int s = 0; s < (1<<n); ++s) {
    bool suc = true;
    for(int i = 0; i < n; ++i) {
      if(!(s & (1<<i)) && p[i].x == 1) {
        suc = false;
        break;
      }
    }
    if(!suc) continue;
    dfs(s, 0, "", true);
  }
  sort(ans.begin(), ans.end(), cmp);
  for(int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}

/*
2
required_multi_param 1 1 0
1,2
optional_with_negative 0 0 1
own1,own2
*/

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

string change[3] = {"A", "B", "C"};

int solve(string word) {
  int ans = 0;
  for(int i = 0; i < word.size(); ++i) {
    for(int t = 0; t < 3; ++t) {
      string word1 = word.substr(0, i+1) + change[t] + word.substr(i+1);
      int cnt = 0;
      while(true) {
        string word2 = "";
        bool suc = false;
        for(int j = 0; j < word1.size();) {
            int k = j;
            while(k < word1.size() && word1[k] == word1[j]) {
              ++k;
            }
            if(k - j > 1) {
              suc = true;
              cnt += k - j;
            }
            else {
              word2 += word1[j];
            }
            j = k;
        }
        if(!suc) {
          break;
        }
        word1 = word2;
      }
      if(cnt > ans) {
        ans = cnt;
      }
    }
  }
  return ans;
}

int main() {
  int n;gn(n);
  for(int i = 0; i < n; ++i) {
    string word;
    cin >> word;
    cout << solve(word) << endl;
  }
  return 0;
}

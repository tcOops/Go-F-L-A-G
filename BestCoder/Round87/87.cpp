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

const int N = 1e6 + 10;
string word;
int n, m;

int main() {
  int T; gn(T);
  while(T--) {
    gn(n); gn(m);
    cin >> word;

    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n/2; ++i) {
      if(word[i] == word[n/2+i]) {
        cnt1++;
      }
      else {
        cnt2++;
      }
    }

    int up = cnt1*2 + 2*cnt2, down = cnt2;
    if(up < m || down > m || (m & 1 && (cnt2 == 0))) {
      printf("Impossible\n");
      continue;
    }

    string ans = "";
    for(int i = 0; i < n/2; ++i) {
      if(word[i] == word[i+n/2]) {
        if(word[i] == 'a') {
          int res1 = (cnt1 - 1)*2 + cnt2*2;
          int res2 = cnt2;
          if(res1 >= m && res2 <= m) {
            ans += 'a';
            --cnt1;
          }
          else {
            ans += 'b';
            --cnt1, m -= 2;
          }
        }
        else {
          int res1 = (cnt1 - 1)*2 + cnt2*2;
          int res2 = cnt2;
          if(res1 + 2 >= m && res2 + 2 <= m) {
            ans += 'a';
            --cnt1, m -= 2;
          }
          else {
            ans += word[i];
            --cnt1;
          }
        }
      }

      else {
        if(word[i] == 'a' || word[i+n/2] == 'a') {
          int res1 = cnt1*2 + (cnt2-1)*2;
          int res2 = cnt2 - 1;

          bool flag = true;
          if(m < 1 || (((m - 1) & 1) && (cnt2 == 1))) {
            flag = false;
          }
          if(res1 + 1 >= m && res2 + 1 <= m && flag) {
            ans += 'a';
            --cnt2; --m;
          }
          else {
            for(int j = 0; j < 26; ++j) {
              if('a' + j != word[i] && 'a' + j != word[i+n/2]) {
                ans += 'a' + j;
                break;
              }
            }
            --cnt2; m -= 2;
          }
        }
        else {
          int res1 = cnt1*2 + (cnt2-1)*2;
          int res2 = cnt2 - 1;
          bool flag = true;
          if((m < 2) || ((m - 2) & 1 && (cnt2 == 1))) {
            flag = false;
          }
          if(res1 + 2 >= m && res2 + 2 <= m && flag) {
            ans += 'a';
            --cnt2; m -= 2;
          }
          else {
            ans += min(word[i], word[i+n/2]);
            --cnt2, --m;
          }
        }
      }
    }
    cout << ans << ans << endl;
  }
  return 0;
}

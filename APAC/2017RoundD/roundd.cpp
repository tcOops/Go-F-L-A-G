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

/*
const int N = 100010;
map<string, int > voc;
set<string> uniqu;
int n, m;
vector<string > backup;
long long dp[N];

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, n, cases = 1;
  gn(T);
  while(T--) {
    scanf("%d %d", &n, &m);
    string tmp;
    voc.clear(), uniqu.clear();
    for(int i = 0; i < n; ++i) {
      cin >> tmp;
      if(uniqu.find(tmp) != uniqu.end()) {
        continue;
      }
      sort(tmp.begin(), tmp.end());
      voc[tmp] += 1;
    }
    printf("Case #%d: ", cases++);
    for(int i = 0; i < m; ++i) {
      cin >> tmp;
      memset(dp, 0, sizeof(dp));
      dp[0] = 1;
      for(int j = 0; j < tmp.size(); ++j) {
        string res = "";
        for(int k = j; k >= 0; --k) {
          res += tmp[k];
          sort(res.begin(), res.end());
          dp[j+1] += dp[k] * voc[res] % MOD;
        }
      }
      printf("%lld ", dp[tmp.size()]);
    }
    cout << endl;
  }
  return 0;
}
复杂度O(n*len1*lg(n) + m*len2*len2*(lg(len2)+lg(n)*len1));
仅仅可以过small-data
*/

const int N = 410;
const int M = 40010;
int dp[M];
int cnt[N][26];
int cur, b[26], len[N];
int tnt;
string s;
vector<int > fit[M];

inline int Inc(int u, int v) {
  return u + v - (u + v >= MOD ? MOD : 0);
}

inline void update(int idx, int pos, int val) {
  tnt -= (cnt[idx][pos] == b[pos]);
  b[pos] += val;
  tnt += (cnt[idx][pos] == b[pos]);
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, cases = 1; gn(T);
  int n, m;
  while(T--) {
    gn(n); gn(m);
    for(int i = 0; i < n; ++i) {
      cin >> s;
      len[i] = s.size();
      memset(cnt[i], 0, sizeof(cnt[i]));
      for(int j = 0; j < len[i]; ++j) {
        cnt[i][s[j]-'a']++;
      }
    }

    printf("Case #%d: ", cases++);
    for(int k = 0; k < m; ++k) {
      cin >> s;
      int LEN = s.size();
      for(int i = 0; i < LEN; ++i) {
        dp[i+1] = 0;
        fit[i].clear();
      }
      for(int i = 0; i < n; ++i) {
        if(len[i] > LEN) continue;
        tnt = 0;
        for(int j = 0; j < 26; ++j) {
          b[j] = 0;
          tnt += (cnt[i][j] == 0);
        }
        for(int j = 0; j < len[i] - 1; ++j) {
          update(i, s[j]-'a', 1);
        }
        for(int j = len[i] - 1; j < LEN; ++j) {
          update(i, s[j]-'a', 1);
          if(tnt == 26) {
            fit[j].push_back(j - len[i]);
        //    cout << "YEEE " << j - len[i] << endl;
          }
          update(i, s[j-len[i]+1]-'a', -1);
        }
      }
      dp[0] = 1;
      for(int i = 0; i < LEN; ++i) {
        for(int j = 0; j < fit[i].size(); ++j) {
          dp[i+1] = Inc(dp[i+1], dp[fit[i][j]+1]);
        }
      }
      printf("%d ", dp[LEN]);
    }
    puts("");
  }
  return 0;
}

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
#include <bitset>
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

const int N = 1010;
int cnt[N][4];

int main() {
  int T; gn(T);
  int k;
  string gene;
  while(T--) {
    cin >> gene >> k;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < min(k, (int)gene.size() - k); ++i) {
      for(int j = i; j < gene.size(); j += (int)gene.size() - k) {
        switch(gene[j]) {
          case 'A':
            cnt[i][0]++;
            break;
          case 'T':
            cnt[i][1]++;
            break;
          case 'C':
            cnt[i][2]++;
            break;
          case 'G':
            cnt[i][3]++;
            break;
        }
      }
    }

    int ans = 0;
    for(int i = 0; i < min((int)gene.size() - k, k); ++i) {
      int sum = cnt[i][0] + cnt[i][1] + cnt[i][2] + cnt[i][3];
      int maxChange = 1e9;
      for(int j = 0; j < 4; ++j) {
        if(sum - cnt[i][j] < maxChange) {
          maxChange = sum - cnt[i][j];
        }
      }
      ans += maxChange;
    }
    cout << ans << endl;
  }
  return 0;
}

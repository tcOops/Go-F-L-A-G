//AC

// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

// 8道水题

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

const int N = 1010;
int a[N];
set<int > st;


int main() {
  int T, n, l;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &n, &l);
    for(int i = 1; i <= l; ++i) {
      scanf("%d", &a[i]);
    }

    bool ans = false;
    for(int i = 1; i <= min(l, n); ++i) {
//        cout << i << t << endl;
        st.clear();
        bool suc = true;
        for(int j = 1; j < i; ++j) {
          if(st.count(a[j])) {
            suc = false;
            break;
          }
          st.insert(a[j]);
        }
        if(!suc) {
          continue;
        }

        st.clear();
        for(int j = i; j <= l; ++j) {
          if(st.count(a[j])) {
            suc = false;
            break;
          }
          st.insert(a[j]);
          if(st.size() == n) {
            st.clear();
          }
        }

        if(suc) {
          ans = true;
          break;
        }
    }
    if(ans) {
      cout << "CAN'T DECIDE" << endl;
    }
    else {
      cout << "B" << endl;
    }
  }
  return 0;
}

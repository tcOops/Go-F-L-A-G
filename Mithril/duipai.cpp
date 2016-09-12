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
const ll mod=1000000007;
const int N = 100010;

int m, n;

ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int ans, res[110];

bool judge(int k) {
    for(int i = 0; i < k/2; ++i) {
        if(res[i] != res[k/2+i]) {
            return true;
        }
    }
    return false;
}

void dfs(int k) {
  //  printf("%d\n", k);
    if(k == n) {
        ++ans;
        return ;
    }

    ++ans;
    if((k+1) & 1) {
        for(int i = 0; i < m; ++i) {
            res[k] = i;
            dfs(k+1);
        }
    }

    else {
        for(int i = 0; i < m; ++i) {
            res[k] = i;
            if(judge(k+1)) {
                dfs(k+1);
            }
        }
    }
}

#define http cout << "mobaiyzw" << endl; goto gaclib; gaclib

int main() {
//#define RejudgeX
#ifdef RejudgeX
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
/*
    while(~scanf("%d%d", &n, &m)) {
      ans = 0;
      dfs(0);
      printf("%d\n", ans - 1);
    }
*/
    http://mobaiyuzhiwei
    return 0;
}

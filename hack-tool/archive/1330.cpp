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
const int N = 110;

int b[N], cnt[N], vis[N];
vector<int > lcm;

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    b[x] = i;
  }

  memset(vis, 0, sizeof(vis));
  memset(cnt, 0, sizeof(cnt));
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      int j = i, n = 0;
      do {
        vis[j] = 1;
        j = b[j], ++n;
      }while(j != i);
      cnt[n]++;
    }
  }

  lcm.clear();
  for(int i = 1; i <= n; ++i) {
    if(cnt[i] != 0) {
      lcm.push_back(i);
    }
  }

  int ans = lcm[0];
  for(int i = 1; i < lcm.size(); ++i) {
    ans = ans * lcm[i] / gcd(ans, lcm[i]);
  }
  printf("%d\n", ans);
  return 0;
}

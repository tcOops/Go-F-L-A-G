// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

// Hackerank -> HourRank 9
// Easy
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
const int N = 1010;

int loave[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &loave[i]);
  }

  int ans = 0, idx = 1;
  while(idx <= n) {
    if(loave[idx] & 1) {
      int j = idx + 1;
      while(j <= n) {
        if(loave[j] & 1) {
          ans += 2;
          break;
        }
        ans += 2, ++j;
      }
      if(j == n + 1) {
        puts("NO");
        return 0;
      }
      idx = j + 1;
    }
    else {
      ++idx;
    }
  }

  cout << ans << endl;
  return 0;
}

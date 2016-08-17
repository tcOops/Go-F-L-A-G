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
const int N = 1010;

int maze[N][N];
int dp[N][N][2];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      scanf("%d", &maze[i][j]);
    }
  }

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      int cnt = 0, tmp = maze[i][j];
      if(tmp == 0) {
        dp[i][j][0] = dp[i][j][1] = 10000000;
        continue;
      }
      while(tmp % 2 == 0) {
        ++cnt, tmp /= 2;
      }

      if(i == 0 && j == 0) {
        dp[i][j][0] = cnt;
      }
      else if(i == 0) {
        dp[i][j][0] = dp[i][j-1][0] + cnt;
      }
      else if(j == 0) {
        dp[i][j][0] = dp[i-1][j][0] + cnt;
      }
      else {
        dp[i][j][0] = min(dp[i-1][j][0], dp[i][j-1][0]) + cnt;
      }

      cnt = 0, tmp = maze[i][j];
      while(tmp % 5 == 0) {
        ++cnt, tmp /= 5;
      }

      if(i == 0 && j == 0) {
        dp[i][j][0] = cnt;
      }
      else if(i == 0) {
        dp[i][j][1] = dp[i][j-1][1] + cnt;
      }
      else if(j == 0) {
        dp[i][j][1] = dp[i-1][j][1] + cnt;
      }
      else {
        dp[i][j][1] = min(dp[i-1][j][1], dp[i][j-1][1]) + cnt;
      }
    }
  }
  printf("%d\n", dp[n-1][n-1][0] < dp[n-1][n-1][1] ? dp[n-1][n-1][0] : dp[n-1][n-1][1]);
  return 0;
}

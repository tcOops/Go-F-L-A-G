#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[210][210];

int solve(int l, int r) {
  if(l >= r) {
    return 0;
  }

  if(dp[l][r] != -1) {
    return dp[l][r];
  }

  int ans = 1e9;
  for(int i = l; i <= r; ++i) {
    int tmp = max(solve(l, i - 1), solve(i + 1, r)) + i;
    if(tmp < ans) {
      ans = tmp;
    }
  }
  dp[l][r] = ans;
  return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(1, n));
    return 0;
}

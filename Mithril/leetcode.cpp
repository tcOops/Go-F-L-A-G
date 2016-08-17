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
const int N = 310;

int dp[N][N];

class Solution {
public:
    int maxCoins(vector<int>& nums) {
      int size = (int)nums.size();
      memset(dp, 0, sizeof(dp));
      for(int i = 0; i < size; ++i) {
        dp[i][i] = nums[i];
      }

      for(int k = 2; k <= size; ++k) {
        for(int i = 0; i + k - 1 < size; ++i) {
          int j = i + k - 1;
          for(int t = i; t <= j; ++t) {
            int left = (i == 0) ? 1 : nums[i-1];
            int right = (j == size - 1) ? 1 : nums[j+1]
            int tmp = dp[i][t-1] + left*nums[t]*right + dp[t+1][j];
            if(tmp > dp[i][j]) {
              dp[i][j] = tmp;
            }
          }
        }
      }
      return dp[0][size-1];
    }
};

int main() {
  Solution sol = Solution();
  vector<int > test = {3, 1, 5, 8};
  cout << sol.maxCoins(test);
  return 0;
}

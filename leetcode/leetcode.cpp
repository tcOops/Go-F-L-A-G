// Author: RejudgeX
// Level -> CF/TC -> Yellow
// > -> Ag
// -> F/L/A/G
// -> Latency 「2017/5/15」

//Two-points topic
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
const int MOD = 1e9 + 7;
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

class Solution {
// Algorithm : Enumerate & Two-points
// Time Complexity : O(nlgn + n^2) = O(n^2)
// The use of unique of Vector (important)

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int> > ans;
			vector<int > res;

			sort(nums.begin(), nums.end());
			for(int i = 0; i < nums.size(); ++i) {
				if(i > 0 && nums[i] == nums[i-1]) continue;
				for(int j = i+1; j < nums.size(); ++j) {
					if(j > i+1 && nums[j] == nums[j-1]) continue;
					int tgt = target - nums[i] - nums[j];
					int l = j + 1, r = nums.size() - 1;
					while(l < r) {
						if(nums[l] + nums[r] == tgt) {
							res.clear();
							res.push_back(nums[i]);
							res.push_back(nums[j]);
							res.push_back(nums[l]);
							res.push_back(nums[r]);
							ans.push_back(res);
							++l, --r;
						}
						else if(nums[l] + nums[r] < tgt) {
							++l;
						}
						else {
							--r;
						}
					}
				}
			}

			vector<vector<int > >::iterator it = unique(ans.begin(), ans.end());
			if(it != ans.end()) {
				ans.erase(it, ans.end());
			}
			return ans;
    }
};

int main() {
  Solution sol = Solution();
  int a[6] = {1, 0, -1, 0, -2, 2};
  vector<int > test(a, a+6);

  return 0;
}

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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

set<int > st;

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
			st.clear();
    }

    void addNum(int val) {
			st.insert(val);
    }

    vector<Interval> getIntervals() {
			vector<Interval> ans;
			int begin = -1;
			for(set<int >::iterator it = st.begin(); it != st.end();) {
				if(begin == -1) {
					begin = *it;
					++it;
				}
				int end = begin;
				while(it != st.end() && (*it == end || *it == end + 1)) {
					end = *it;
					++it;
				}
				ans.push_back(Interval(begin, end));
				if(it == st.end()) break;
				begin = *it;

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

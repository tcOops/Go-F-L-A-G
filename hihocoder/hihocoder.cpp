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

struct student {
  long long id;
  int cnt;
  vector<pair<int, int> > regis;
}stu[10010];
vector<pair<int, int> > ans;

struct job{
  int student_idx, office_id;
  int begin, duration;
  job(int studentIdx, int officeId, int begin_, int duration_) {
    student_idx = studentIdx, office_id = officeId, begin = begin_, duration = duration_;
  }
  bool operator<(const job &rhs) const {
    return begin > rhs.begin || (begin == rhs.begin && stu[student_idx].id > stu[rhs.student_idx].id);
  }
};
priority_queue<job > pq;
int pos[10010], pre[110];
int N, M, K;

//sb 模拟
int main() {
  gn(N); gn(M); gn(K);
  for(int i = 0; i < N; ++i) {
    int getTime;
    gn(stu[i].id); gn(getTime); gn(stu[i].cnt);
    for(int j = 0; j < stu[i].cnt; ++j) {
      int x, y;
      gn(x); gn(y);
      stu[i].regis.push_back(make_pair(x, y));
    }
    pq.push(job(i, stu[i].regis[0].first, getTime + K, stu[i].regis[0].second));
    pos[i] = 1;
  }

  memset(pre, -1, sizeof(pre));
  while(!pq.empty()) {
    job p = pq.top();
  //  printf("%d %d %d %d\n", p.student_idx, p.office_id, p.begin, p.duration);
    pq.pop();
    int cur = p.student_idx;
    if(pre[p.office_id] > p.begin) {
      p.begin = pre[p.office_id];
    }
    int finishTime = p.begin + p.duration;
    if(pos[cur] == stu[cur].cnt) {
      ans.push_back(make_pair(cur, finishTime));
    }
    else {
      int jobId = stu[cur].regis[pos[cur]].first;
      int durationTime = stu[cur].regis[pos[cur]].second;
      pq.push(job(cur, jobId, finishTime + K, durationTime));
      pos[cur]++;
    }
    pre[p.office_id] = finishTime;
  }

  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); ++i) {
    printf("%d\n", ans[i].second);
  }
  return 0;
}

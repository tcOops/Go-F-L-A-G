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


typedef pair<int,int>P;
const int N=50010,inf=1000000010;
long long n,m,i,a[N];
bool vis[N];
queue<int > q;
long long d[N];
P t;
priority_queue<P,vector<P>,greater<P> >Q;
long long x;

inline void read(int&a){char c;while(!(((c=getchar())>='0')&&(c<='9')));a=c-'0';while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';}

int main(){
    m = inf;
    for(gn(n);i<n;i++) {
      gn(a[i]);
      if(m > a[i]) {
        m = a[i];
      }
    }

    for(i=1;i<m;i++) d[i]=inf;
    Q.push(P(0,0));
    vis[0] = true;
    q.push(0);
    d[0] = 0;

    while(!q.empty()) {
      int p = q.front();
      q.pop();
      vis[p] = false;
      for(int i = 0; i < n; ++i) {
        int tmp = (p+a[i])%m;
        if(d[p] + a[i] < d[tmp]) {
          d[tmp] = d[p] + a[i];
          if(!vis[tmp]) {
            q.push(tmp);
            vis[tmp] = true;
          }
        }
      }
    }

/*
    while(!Q.empty()){
        t=Q.top();Q.pop();
        if(d[t.second]<t.first)continue;
        for(x=t.second,i=0;i<n;i++)if(d[x]+a[i]<d[(x+a[i])%m])Q.push(P(d[(x+a[i])%m]=d[x]+a[i],(x+a[i])%m));
    }
*/

    for(gn(n);n--;puts(d[x%m]<=x?"Yes":"No")) gn(x);
    return 0;
}

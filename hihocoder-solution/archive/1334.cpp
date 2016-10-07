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

const int N = 41;

//vector<int > g[N];
int n, dp[N];
string doc[N];

int g[N][N],best,num[N];

bool dfs(int *tmp,int total,int cnt) {
    int i,j,k,a[N];
    if(!total){
        if(best<cnt){
            best=cnt;
            return true;
        }
        return false;
    }
    for(i=0;i<total;i++) {
        if(cnt+(total-i)<=best)return false;
        if(cnt+num[tmp[i]]<=best)return false;
        for(k=0,j=i+1;j<total;j++)
            if(g[tmp[i]][tmp[j]])
                a[k++]=tmp[j];
        if(dfs(a,k,cnt+1))
            return true;
        
    }
    return false;
}

int MaxNumClique(){
    int i,j,k,tmp[N];
    best=0;
    for(i=n-1;i>=0;i--){
        for(k=0,j=i+1;j<n;j++)
            if(g[i][j])
                tmp[k++]=j;
        dfs(tmp,k,1);
        num[i]=best;			
    }
    return best;
}

int main() {
    gn(n);
    for(int i = 0; i < n; ++i) {
        cin >> doc[i];
        sort(doc[i].begin(), doc[i].end());
    }

    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            bool suc = true;
            for(int s1 = 0, s2 = 0; doc[i][s1] && doc[j][s2];) {
                if(doc[i][s1] == doc[j][s2]) {
                    suc = false;
                    break;
                }
                else {
                    if(doc[i][s1] > doc[j][s2]) {
                        ++s2;
                    }
                    else {
                        ++s1;
                    }
                }
            }
            
            if(suc) {
              //  g[i].push_back(j), g[j].push_back(i);
                g[i][j] = 1;
                g[j][i] = 1;
            }
        }
    }
    
    int ans = 0;
    ans = MaxNumClique();
    printf("%d\n", ans);
    return 0;
}
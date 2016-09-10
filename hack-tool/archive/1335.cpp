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

const int N = 10010;
int fa[N];
map<string, int> emailMap;
vector<string > userNames;
vector<vector<string> > ans;
map<int, int> vis;

int find(int x) {
    if(fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

int main() {
    int n, m;
    gn(n);
    for(int i = 0; i < n; ++i) {
        fa[i] = i;
    }
    
    for(int i = 0; i < n; ++i) {
        string userName; cin >> userName;
        userNames.push_back(userName);
        scanf("%d", &m);
        for(int j = 0; j < m; ++j) {
            string email; cin >> email;
            if(emailMap.find(email) == emailMap.end()) {
                emailMap[email] = i;
            }
            else {
                int fx = find(i), fy = find(emailMap[email]);
                fa[fx] = fy;
            }
        }
    }
    
    /*
    for(int i = 0; i < n; ++i) {
        int fi = find(i);
        ans[fi].push_back(userNames[i]);
    }
    
    for(int i = 0; i < n; ++i) {
        if(ans[i].size() > 0) {
            for(int j = 0; j < ans[i].size(); ++j) {
                printf("%s ", ans[i][j].c_str());
            }
            cout << endl;
        }
    }
     */
    
    for(int i = 0; i < n; ++i) {
        int fi = find(i);
        if(vis.find(fi) == vis.end()) {
            ans.push_back({userNames[i]});
            vis[fi] = ans.size() - 1;
        }
        else {
            ans[vis[fi]].push_back(userNames[i]);
        }
    }
    
    for(int i = 0, l = ans.size(); i < l; ++i) {
        for(int j = 0, ll = ans[i].size(); j < ll; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
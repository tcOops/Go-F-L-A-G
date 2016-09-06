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

const int N = 30000 + 10;

//倍增 -> 后缀数组
//Start index: Sa -> 1, rank -> 0, height -> 1(Same with sa), [sa[1], sa[2]....sa[n] = range(0, n)] | [(rank[0], rank[2]....rank[n-1] = range(1, n+1)]

int wa[N], wb[N], wv[N], Ws[N];
int cmp(int *r,int a,int b,int l) {
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(const char *r, int *sa, int n, int m){
    int i, j, p, *x=wa, *y=wb, *t;
    for(i = 0; i < m; ++i) Ws[i] = 0;
    for(i = 0; i < n; ++i) Ws[x[i] = r[i]]++;
    for(i = 1; i < m; ++i) Ws[i] += Ws[i-1];
    for(i = n-1; i >= 0; --i) sa[--Ws[x[i]]] = i;
    
    for(j = 1, p = 1; p < n; j *= 2, m = p) {
        for(p = 0, i = n-j; i < n; ++i) y[p++] = i;
        for(i = 0; i < n; ++i) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; ++i) wv[i] = x[y[i]];
        for(i = 0; i < m; ++i) Ws[i] = 0;
        for(i = 0; i < n; ++i) Ws[wv[i]]++;
        for(i = 1; i < m; ++i) Ws[i] += Ws[i-1];
        for(i = n-1; i >= 0; --i) sa[--Ws[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]]=0,i = 1; i < n; ++i)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j) ? p-1 : p++;
    }
}

int sa[N], Rank[N], height[N];
//Get height
void calheight(const char *r, int *sa, int n) {
    int i, j, k = 0;
    for(i = 1; i <= n; ++i) Rank[sa[i]] = i;
    for(i = 0; i < n; height[Rank[i++]] = k)
        for(k ? --k : 0, j = sa[Rank[i]-1]; r[i+k] == r[j+k]; ++k);
}

char word[N];
int lcp[N][16];
int Log[N];

void st(int *height, int n) {
    for(int i = 1; i <= n; ++i) {
        lcp[i][0] = height[i];
    }
    
    for(int k = 1; k < 16; ++k) {
        for(int i = 1; i + (1<<k) - 1 <= n; ++i) {
            lcp[i][k] = min(lcp[i][k-1], lcp[i+(1<<(k-1))][k-1]);
        }
    }
    
    for(int i = 1; i < N; ++i) {
        int u = i;
        Log[i] = -1;
        while(u) {
            ++Log[i], u >>= 1;
        }
    }
}

int getLCP(int x, int y, int *rank) {
    int rankx = rank[x], ranky = rank[y];
    if(rankx > ranky) {
        swap(rankx, ranky);
    }
    ++rankx;
    
    int v = ranky - rankx + 1;
    int l = Log[v];
    int ans = min(lcp[rankx][l], lcp[ranky - (1<<l) + 1][l]);
//    cout << x << " " << y << " " << ans << endl;
    return ans;
 }

int main() {
    int T;
    gn(T);
    while(T--) {
        gets(word);
        int len = strlen(word);
        da(word, sa, len + 1, 130);
        calheight(word, sa, len);
     //   for(int i = 1; i <= len; ++i) {
     //       printf("%d ", height[i]);
     //   }
        st(height, len);
        long long ans = 0;
        for(int i = 1; i < len; ++i) {
            long long lCnt = 0, rCnt = 0;
            for(int l = 2; i - l + 1 >= 0; l += 2) {
                int common = getLCP(i - l/2 + 1, i - l + 1, Rank);
                if(common >= l / 2) {
                    ++lCnt;
                }
            }
            
            for(int l = 2; i + 1 + l - 1 < len; l += 2) {
                int common = getLCP(i + 1, i + 1 + l/2, Rank);
                if(common >= l / 2) {
                    ++rCnt;
                }
            }
            
       //     cout << "sss  " << i << " " << lCnt << " " << rCnt << endl;
            ans += lCnt * rCnt;
        }
        cout << ans << endl;
    }
    return 0;
}


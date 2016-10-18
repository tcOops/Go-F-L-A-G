

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
const ll mod = 1000000007;

ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
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

const int N = 200010;
int save[N<<1];
char op[12];

int main() {
  int T,cases = 1; gn(T);
  while(T--) {
    int n;
    scanf("%d", &n);
    int head = 0, tail = 1;
    int l = N, r = N;
    bool sta = 1;
    printf("Case #%d:\n", cases++);
    for(int i = 0; i < n; ++i) {
      int val;
      scanf("%s", op);

      switch(op[2]) {
        case 'S':
          scanf("%d", &val);
          if(sta) {
            ++head;
            if(val == 0) {
              save[++r] = head;
            }
          }
          else {
            --tail;
            if(val == 0) {
              save[l--] = tail;
            }
          }
          break;
        case 'P':
          if(sta) {
            if(l < r && save[r] >= head) {
              --r;
            }
            --head;
          }
          else {
            if(l < r && save[l+1] <= tail) {
              ++l;
            }
            ++tail;
          }
          break;
        case 'V':
          sta ^= 1;
          break;
        case 'E':
          if(tail > head) {
            printf("Invalid.\n");
          }
          else {
            if(l == r) {
              printf("%d\n", (head - tail + 1) & 1);
            }
            else {
              if(sta) {
                int cnt = save[l+1] - tail;
                if(head > save[l+1]) {
                  ++cnt;
                }
                printf("%d\n", cnt&1);
              }
              else {
                int cnt = head - save[r];
                if(tail < save[r]) {
                  ++cnt;
                }
                printf("%d\n", cnt&1);
              }
            }
          }
          break;
      }
    }
  }
  return 0;
}

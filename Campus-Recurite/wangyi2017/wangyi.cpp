//AC

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
#include <bitset>
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

// head
const int N = 100010;
int a[N];
struct trie {
  int val;
  trie *next[2];
  trie() {
    memset(next, NULL, sizeof(next));
    val = 0;
  }
};
int dig[41], b[41];

void insert(trie *root, int k) {
  memset(dig, 0, sizeof(dig));
  int cnt = 0;
  while(k) {
    dig[cnt++] = k%2;
    k /= 2;
  }

  trie *p = root;
  for(int i = 40; i >= 0; --i) {
    if(p->next[dig[i]] == NULL) {
      trie *q = new trie();
      p->next[dig[i]] = q;
    }
    p = p->next[dig[i]];
    p->val += 1;
  }
}

int query(trie *root, int k, int m) {
  memset(dig, 0, sizeof(dig));
  memset(b, 0, sizeof(b));
  int cnt = 0;
  while(k) {
    dig[cnt++] = k&1;
    k /= 2;
  }

  cnt = 0;
  while(m) {
    b[cnt++] = m&1;
    m >>= 1;
  }

  trie *p = root;
  long long ans = 0;
  for(int i = 40; i >= 0; --i) {
    if(dig[i] == 0) {
      if(p->next[b[i]^1]) {
        ans += p->next[b[i]^1]->val;
      }
      p = p->next[b[i]];
    }
    else {
      p = p->next[b[i]^1];
    }
    if(p == NULL) break;
  }
  return ans;
}

int main() {
  int n, m;
  gn(n); gn(m);
  trie *root = new trie();
  for(int i = 1; i <= n; ++i) {
    gn(a[i]);
    insert(root, a[i]);
  }

  long long ans = 0;
  for(int i = 1; i <= n; ++i) {
    long long res = query(root, m, a[i]);
    ans += res;
  }
  cout << ans/2 << endl;
  return 0;
}

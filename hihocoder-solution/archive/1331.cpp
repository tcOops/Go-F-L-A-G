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
const int N = 110;

int bits[N];
int ans;

void solve(int bit) {
  if(bit == 0) {
    if(bits[0] <= 2) {
      ++ans;
    }
    return ;
  }

  if(bits[bit] >= 4) {
    return ;
  }
  if(bits[bit] == 3) {
    bits[bit-1] += 2;
    solve(bit-1);
    bits[bit-1] -= 2;
  }
  else {
    for(int j = 0; j < 2 && j <= bits[bit]; ++j) {
      bits[bit-1] += j*2;
      solve(bit-1);
      bits[bit-1] -= j*2;
    }
  }
}

int main() {
  int n, cnt;
  while(~scanf("%d", &n)) {
    if(n == 0) {
      printf("0");
      continue;
    }
    cnt = 0;
    while(n) {
      if(n & 1) {
        bits[cnt++] = 1;
      }
      else {
        bits[cnt++] = 0;
      }
      n >>= 1;
    }


    ans = 0;
    solve(cnt - 1);
    printf("%d\n", ans);
  }
  return 0;
}

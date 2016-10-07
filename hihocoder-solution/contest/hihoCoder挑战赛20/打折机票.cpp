#include <cstdio>
#include <cstring>
#define maxab(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
int dp[100010][23];
int a[100010];

void pre(int n) {
    for(int i = 0; i < n; ++i) {
        dp[i][0] = a[i];
    }
    
    for(int j = 1; j < 22; ++j){
        for(int k = 0; k + (1<<j) - 1 <= n; ++k) {
            dp[k][j] = maxab(dp[k][j-1], dp[k+(1<<(j-1))][j-1]);
        }
    }
}

void solve(int left, int right) {
    int v = right - left + 1;
    int l = 0, r = 30;
    while(l < r) {
        int mid = (l+r+1) >> 1;
        if((1<<mid) > v){
            r = mid - 1;
        }
        else{
            l = mid;
        }
    }
    
    int ans = maxab(dp[left][l], dp[right-(1<<l)+1][l]);
    if(ans == -1) {
        printf("None\n");
    }
    else {
        printf("%d\n", ans);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    memset(a, -1, sizeof(a));
    
    for(int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(a[x] < y) {
            a[x] = y;
        }
    }

    pre(n);

    for(int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        solve(l, r);
    }
    return 0;
}
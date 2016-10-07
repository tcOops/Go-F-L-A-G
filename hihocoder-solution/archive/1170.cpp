#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
  
const int N = 100005;  
  
typedef long long ll;  
const ll INF = 1000000000000000LL;  
  
int t, n, k, a;  
ll dp[1<<17];  
vector<int> g[20];  
ll G[20][20];  
  
int main() {  
    int cas = 0;  
    scanf("%d", &t);  
    while (t--) {  
        scanf("%d%d", &n, &k);  
        for (int i = 1; i <= k; i++) g[i].clear();  
        for (int i = 1; i <= n; i++) {  
            scanf("%d", &a);  
            g[a].push_back(i);  
        }  
        for (int i = 1; i <= k; i++) {  
            for (int j = 1; j <= k; j++) {  
                if (i == j) continue;  
                int cnt = 0;  
                ll ans = 0;  
                for (int k = 0; k < g[j].size(); k++) {  
                    while (cnt < g[i].size() && g[i][cnt] < g[j][k]) cnt++;  
                    ans += cnt;  
                }  
                G[j][i] = ans;  
            }  
        }  
        for (int i = 0; i < (1<<k); i++)  
            dp[i] = INF;  
        dp[0] = 0;  
        for (int i = 1; i < (1<<k); i++) {  
            for (int j = 1; j <= k; j++) {  
                if (i&(1<<(j - 1)) == 0) continue;  
                ll sum = 0;  
                for (int x = 1; x <= k; x++) {  
                    if (x == j) continue;  
                    if (i&(1<<(x - 1))) {  
                        sum += G[x][j];  
                    }  
                }  
                dp[i] = min(dp[i^(1<<(j - 1))] + sum, dp[i]);  
            }  
        }  
        printf("Case #%d: %lld\n", ++cas, dp[(1<<k) - 1]);  
    }  
    return 0;  
}  
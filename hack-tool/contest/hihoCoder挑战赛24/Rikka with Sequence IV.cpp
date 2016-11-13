#include <cstdio>
#include <vector>
using namespace std;

int a[1010];
bool vis[1010];
vector<int > ans;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    
    long long sum = 0;
    bool suc = true;
    for(int i = 1; i <= n; ++i) {
        bool sta = false;
        for(int j = 1; j <= n; ++j) {
            if(!vis[j] && sum + a[j] >= 0) {
                vis[j] = 1;
                ans.push_back(j);
                sum += a[j];
                sta = true;
                break;
            }
        }
        if(!sta) {
            suc = false;
            break;
        }
    }
    if(suc) {
        for(int i = 0; i < n; ++i) {
            printf("%d ", ans[i]);
        }
    }
    else {
        printf("Impossible");
    }
    puts("");
    return 0;
}
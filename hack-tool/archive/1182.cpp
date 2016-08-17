#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int sta[16];
int g[1<<15][2];
int stack[1<<15], cnt = 0;
int n;
vector<int > ans;


void fluery(int u) {
    int v, rev = ((1<<n)-1)^(1<<(n-1));
    if((v = g[u][0]) != -1) {
        g[u][0] = -1;
        fluery(v & rev);
    }
    
    if((v = g[u][1]) != -1) {
        g[u][1] = -1;
        fluery(v & rev);
    }
    stack[cnt++] = u;
}

int main() {
    scanf("%d", &n);
    if(n == 1) {
        printf("01\n");
        return 0;
    }
    memset(g, -1, sizeof(-1));
    for(int i = 0; i < (1<<(n-1)); ++i) {
        g[i][0] = (i<<1);
        g[i][1] = (i<<1|1);
    }
    
    fluery(0);
    
    for(int i = 1; i < n; ++i) {
        ans.push_back(stack[cnt-1] & (1<<i));
    }
    
    for(int i = cnt-2; i >= 0; --i) {
        ans.push_back(stack[i] & 0x01);
    }
    
    for(int i = 0; i < (1<<n); ++i) {
        printf("%d", ans[i]);
    }
    return 0;
}
#include <cstdio>
using namespace std;
const int N = 110;
int a[N];

void solve(int l, int r) {
    if(l > r) {
        return ;
    }
    int MIN = 1e9, idx;
    for(int i = l; i <= r; ++i) {
        if(a[i] < MIN) {
            MIN = a[i];
            idx = i;
        }
    }
    printf("%d ", a[idx]);
    solve(l, idx - 1);
    solve(idx + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    solve(1, n);
    return 0;
}
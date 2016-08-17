#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int > ans;
string pre, mid;

void solve(int l, int r, int root) {
    if(l > r) {
        return ;
    }
    
    int idx = l;
    for(; idx <= r; ++idx) {
        if(mid[idx] == pre[root]) {
            solve(l, idx-1, root+1);
            solve(idx+1, r, root+(idx-l)+1);
            ans.push_back(pre[root]);
            break;
        }
    }
}

int main() {
    cin >> pre >> mid;
    ans.clear();
    solve(0, pre.size()-1, 0);
    for(int i = 0; i < ans.size(); ++i) {
        printf("%c", ans[i]);
    }
    return 0;
}
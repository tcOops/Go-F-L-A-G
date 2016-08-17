#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> candy;

int main() {
    string op;
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        cin >> op;
        if(op[0] == 'A') {
            scanf("%d", &m);
            candy.push(m);
        }
        else {
            printf("%d\n", candy.top());
            candy.pop();
        }
    }
    return 0;
}
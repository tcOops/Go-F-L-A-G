#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
using namespace std;

string a, b;
map<string, int> mp;
map<int, string> res;
set<int > in;
int fa[110];

int main() {
    int n, m;
    scanf("%d", &n);
    mp.clear();
    res.clear();
    memset(fa, 0, sizeof(fa));
    int id = 1;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b;
        if(mp.find(a) == mp.end()) {
            mp[a] = id++;
            res[id-1] = a;
        }
        if(mp.find(b) == mp.end()) {
            mp[b] = id++;
            res[id-1] = b;
        }
        
        fa[mp[b]] = mp[a];
    }
    
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        int ida = mp[a], idb = mp[b];
     //   printf("%d %d\n", ida, idb);
        if(ida == 0 || idb == 0) {
            if(a == b) {
                cout << a << endl;
            }
            else {
                printf("-1\n");
            }
            continue;
        }
        in.clear();
        while(ida >= 1) {
            in.insert(ida);
            ida = fa[ida];
        }
        
        int ans = -1;
        while(idb >= 1) {
            if(in.find(idb) != in.end()) {
                ans = idb;
                break;
            }
            idb = fa[idb];
        }
     //   printf("ans = %d\n", ans);
        if(ans != -1) {
            cout << res[ans] << endl;
        }
        else {
            printf("-1\n");
        }
    }
    return 0;
}


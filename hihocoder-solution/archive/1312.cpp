#include <iostream>
#include <utility>
#include <queue>
#include <set>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;

typedef int Status[10];
typedef pair<int, int> PII;

int f[362880];
int g[362880];
int delta[] = {-1, 1, -3, +3};

int h(Status s){
    int ret = 0;
    for(int i = 1; i <= 9; i++){
        int r1 = (i - 1) / 3;
        int c1 = (i - 1) % 3;
        int v = s[i];
        if(v == 9)  continue;
        int r2 = (v - 1) / 3;
        int c2 = (v - 1) % 3;
        ret += (r1 > r2 ? r1 - r2: r2 - r1) + (c1 > c2? c1 - c2: c2 - c1);
    }
    return ret;
}

int cantor(Status s){
    int ret = 0;
    for(int i = 1; i <= 9; i++){
        int cnt = 0;
        int fac = 1;
        for(int j = i + 1; j <= 9; j++){
            fac *= (10 - j);
            if(s[i] > s[j])   cnt++;
        }
        ret += cnt * fac;
    }
    return ret;
}

void uncantor(int val, Status s){
    int a;
    bool used[10] = {false};
    int fac = 1;
    for(int i = 1; i <= 8; i++) fac *= i;
    for(int i = 1; i <= 9; i++){
        a = val / fac;
        val = val % fac;
        if(i < 9)  fac /= (9 - i);

        int cnt = 0;
        for(int j = 1; j <= 9; j++){
            if(!used[j]){
                cnt++;
                if(cnt == a + 1){
                    used[j] = true;
                    s[i] = j;
                    break;
                }
            }
        }
    }
}

void searching(Status s){
    memset(f, -1, sizeof(f));
    memset(g, -1, sizeof(g));
    set<int> vis;
    priority_queue<PII, vector<PII>, greater<PII> > q;

    int val = cantor(s);
    g[val] = 0;
    f[val] = g[val] + h(s);
    q.push(PII(f[val], val));

    while(!q.empty()){
        PII p = q.top();
        q.pop();
        val = p.second;
        if(vis.count(val))  continue;
        if(val == 0){
            assert(g[0] >= 0);
            cout << g[0] << endl;
            return;
        }
        uncantor(val, s);
        vis.insert(val);

        int pos = 0;
        for(int i = 1; i <= 9; i++){
            if(s[i] == 9){
                pos = i;
                break;
            }
        }
        assert(pos != 0);
        Status ns;
        for(int k = 0; k < 4; k++){
            int np = pos + delta[k];
            if(np >= 1 && np <= 9 && (k > 1 || (pos - 1) / 3 == (np - 1) / 3)){
                memcpy(ns, s, sizeof(Status));
                ns[np] = s[pos];
                ns[pos] = s[np];

                int nv = cantor(ns);
                int hh = h(ns);
                if(vis.count(nv)) continue;
                else if(f[nv] != -1){
                    if(g[nv] > g[val] + 1){
                        g[nv] = g[val] + 1;
                    }
                    if(f[nv] > hh + g[val] + 1){
                        f[nv] = hh + g[val] + 1;
                        q.push(PII(f[nv], nv));
                    }
                }else{
                    g[nv] = g[val] + 1;
                    f[nv] = hh + g[nv];
                    q.push(PII(f[nv], nv));
                }
            }
        }
    }

    cout << "No Solution!" << endl;
}

int main(){
    int T;
    cin >> T;
    Status s;
    while(T--){
        for(int i = 1; i <= 9; i++){
            cin >> s[i];
            if(s[i] == 0)   s[i] = 9;
        }
        searching(s);
    }

    return 0;
}

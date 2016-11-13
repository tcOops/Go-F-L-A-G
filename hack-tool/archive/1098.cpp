#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define minab(a, b) ((a) < (b) ? (a) : (b))
const int N = 1000010;

int p[N<<1];
char s[N<<1];
string st;
int mx, idx;//the Rightest postion can be reached now, and the idx

void manacher(char *str) {
    mx = 0, idx = 0;
    int ans = 0;
    memset(p, 0, sizeof(p));
    int size = (int)strlen(str);
   
    for(int i = 1; str[i]; ++i) {
        p[i] = mx > i ? minab(p[idx*2 - i], mx - i) : 1;
        while((p[i] + i < size) && (i - p[i] >= 0) && str[p[i]+i] == str[i-p[i]]) {
            ++p[i];
        }
        
        if(i + p[i] > mx) {
            mx = i + p[i];
            idx = i;
        }
    //    printf("p[i] = %d\n", p[i]);
        if(str[i] == '#') {
            if(((p[i]) / 2) * 2 > ans) {
                ans = (p[i]) / 2 * 2;
            }
        }
        else {
            if((p[i] - 1)/2 * 2 + 1 > ans) {
                ans = (p[i] - 1) / 2 * 2 + 1;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        cin >> st;
        for(int j = 0; j < st.size(); ++j) {
            s[j<<1|1] = '#';
            s[(j<<1) + 2] = st[j];
        }
        s[st.size() << 1 | 1] = '#';
        s[(st.size() << 1) + 2] = '0';
     //   printf("%s\n", s+1);
        manacher(s+1);
    }
    return 0;
}
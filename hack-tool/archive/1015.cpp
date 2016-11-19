#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e4 + 1;
char a[N], b[N*100];
int p[N];

void GetNextArray(int n, char *b){
    int i, j;
    p[0] = -1;
    j = -1;
    for(i = 1; i < n; ++i){
        while(j >= 0 && b[j+1] != b[i]){
            j = p[j];
        }
        if(b[j+1] == b[i]){
            ++j;
        }
        p[i] = j;
    }
}

void KMP(int n1, int n2, char *a, char *b){
    int j = -1, ans = 0;
    for(int i = 0; i < n1; ++i){
        while(j >= 0 && b[j+1] != a[i]){
            j = p[j];
        }
        if(b[j+1] == a[i]){
            ++j;
        }
        if(j == n2-1){
            ++ans;
            j = p[j];
        }
    }
    printf("%d\n", ans);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s%s", a, b);
        int n1 = strlen(a), n2 = strlen(b);
        GetNextArray(n1, a);
        KMP(n2, n1, b, a);
    }
    return 0;
}

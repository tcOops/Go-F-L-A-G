//提交地址: http://hihocoder.com/problemset/problem/1237
//简单数学题

#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;

const int MOD = 19999997;

void gao(LL a[2][2], int n){
    LL b[2][2], c[2][2];
    b[0][0] = 1, b[1][1] = 1, b[1][0] = 0, b[0][1] = 0;
    while(n){
        if(n&1){
            c[0][0] = ((b[0][0]*a[0][0])%MOD + (b[0][1]*a[1][0])%MOD)%MOD;
            c[0][1] = ((b[0][0]*a[0][1])%MOD + (b[0][1]*a[1][1])%MOD)%MOD;
            c[1][0] = ((b[1][0]*a[0][0])%MOD + (b[1][1]*a[1][0])%MOD)%MOD;
            c[1][1] = ((b[1][0]*a[0][1])%MOD + (b[1][1]*a[1][1])%MOD)%MOD;
            for(int i = 0; i < 2; ++i){
                for(int j = 0; j < 2; ++j){
                    b[i][j] = c[i][j];
                }
            }
        }

        n >>= 1;
        c[0][0] = ((a[0][0]*a[0][0])%MOD + (a[0][1]*a[1][0])%MOD)%MOD;
        c[0][1] = ((a[0][0]*a[0][1])%MOD + (a[0][1]*a[1][1])%MOD)%MOD;
        c[1][0] = ((a[1][0]*a[0][0])%MOD + (a[1][1]*a[1][0])%MOD)%MOD;
        c[1][1] = ((a[1][0]*a[0][1])%MOD + (a[1][1]*a[1][1])%MOD)%MOD;
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 2; ++j){
                a[i][j] = c[i][j];
            }
        }
    }
    LL ans = (b[0][0] + b[1][0])%MOD;
    printf("%lld\n", ans);
}

int main(){
    int n;
    while(~scanf("%d", &n)){
    if(n == 1){
        printf("1\n");
    }
    else{
        LL matrix[2][2] = {{1,1}, {1,0}};
        gao(matrix, n-1);
    }
    }
    return 0;
}
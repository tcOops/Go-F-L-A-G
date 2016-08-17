//http://hihocoder.com/contest/hiho91/problem/1
//经典题 贪心 + dp + 单调队列优化

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int M = 5010;
const int N = 1010;
int n, m, k;
int dp[N][M];
int tail[M], head[M];
int q[M][N];

struct node{
    int a, b, c;
    bool operator <(const node &chr) const{
        return b*chr.c > c*chr.b;
    }
}event[N];

int cal(int p, int v, int k){
    int num = (v - p)/(event[k].c);
    int val = event[k].a - m * event[k].b;
    int ret = 0;
    for(int i = 0; i < num; ++i){
        ret += (val + (m-p)*event[k].b);
        p = p + event[k].c;
    }
    return ret;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1;  i <= n; ++i){
        scanf("%d%d%d", &event[i].a, &event[i].b, &event[i].c);
    }
    
    sort(event+1, event+n+1);
    memset(dp, 0, sizeof(dp));
    
    
    for(int i = 1; i <= n; ++i){
        memset(tail, -1, sizeof(tail));
        memset(head, 0, sizeof(head));
        
        for(int j = 0; j < m; ++j){
            int r = j % event[i].c;
            q[r][++tail[r]] = j;
            while(tail[r] > head[r]){
                int val1 = dp[i-1][q[r][tail[r]]] + cal(q[r][tail[r]], j, i);
                int val2 = dp[i-1][q[r][tail[r]-1]] + cal(q[r][tail[r]-1], j, i);
                if(val1 >= val2){
                    q[r][tail[r]-1] = q[r][tail[r]];
                    tail[r]--;
                }
                else{
                    break;
                }
            }
            
            while((j - q[r][head[r]])/event[i].c > k){
                ++head[r];
            }
            dp[i][j] = dp[i-1][q[r][head[r]]] + cal(q[r][head[r]], j, i);
        }
    }

    int ans = 0;
    for(int i = m-1; i >= 0; --i){
        if(dp[n][i] > ans){
            ans = dp[n][i];
        }
    }
    printf("%d\n", ans);
    return 0;
}


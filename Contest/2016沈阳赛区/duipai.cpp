#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define LL long long

LL dp[20][10][2];
LL L,R;
int cas;

void Init()
{
    int i,j,k;
    memset(dp,0,sizeof(dp));
    for(i=0;i<10;i++){
        if((i&1)==0)
            dp[1][i][1] = 1;
        else dp[1][i][0] = 1;
    }

    for(i=2;i<=20;i++){
        for(j=0;j<10;j++){
            for(k=0;k<10;k++){
                if((j&1)==(k&1)){
                    dp[i][j][1] += dp[i-1][k][0];
                    dp[i][j][0] += dp[i-1][k][1];
                }
                else if(j&1){
                    dp[i][j][0] += dp[i-1][k][1];
                }
                else
                    dp[i][j][1] += dp[i-1][k][1];
            }
        }
    }
    return;
}

LL Solve(LL cur)
{
    int i,j,k;
    int arr[105],bitN=0;
    LL tmp = cur,ans=0;
    int num = 0;
    while(tmp){
        arr[++bitN]=tmp%10;
        tmp/=10;
    }
    arr[bitN+1]=0;

    for(i=bitN;i>=1;i--){
        //printf("%d\n",num);
        for(j=0;j<arr[i];j++){
            if(i==bitN&&j>0)ans += dp[i][j][1];
            else if(i<bitN){
                if(j&1){
                    if(arr[i+1]%2==0&&(num%2==1))
                        ans += dp[i][j][1];
                    else if(arr[i+1]%2==1&&(num&1))
                        ans += dp[i][j][0];
                    else if(arr[i+1]%2==1&&!(num&1))
                        ans += dp[i][j][1];
                }
                else{
                    if((arr[i+1]%2==1)&&num%2==0)
                        ans += dp[i][j][1];
                    else if(arr[i+1]%2==0&&num%2==0)
                        ans += dp[i][j][1];
                    else if((arr[i+1]%2==0)&&(num%2==1))
                        ans += dp[i][j][0];
                }
            }
        }

        if(i==bitN){
            num=1;
            continue;
        }
        if((arr[i]&1)!=(arr[i+1]&1)){
            if((arr[i+1]&1)&&(num&1))break;
            if(!(arr[i+1]&1)&&!(num&1))break;
            num=1;
        }
        else num++;
    }

    //solve the leading zero case//
    for(i=bitN-1;i>=1;i--){
        for(j=1;j<=9;j++)
            ans += dp[i][j][1];
    }

    return ans;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    int t;
    Init();
    scanf("%d",&t);
    cas=0;
    while(t--){
        scanf("%lld%lld",&L,&R);
        cas++;
        printf("Case #%d: %lld\n",cas,Solve(R+1)-Solve(L));
    }
    return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
#define mem(name,value) memset(name,value,sizeof(name))
#pragma comment(linker, "/STACK:102400000,102400000")
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=110,inf=0x3f3f3f3f,mod=1000000007;

ll dp[maxn][50],f[500][50][50];
int digit[maxn];
char s[maxn];
int n1,n2,n,m,t;
vector<int>len;

ll dfs(int pos,int j){
    //cout<<pos<<" "<<j<<" "<<x<<" "<<y<<endl;
    if(pos==t) return j==0;
    if(dp[pos][j]!=-1) return dp[pos][j];

    int x=lower_bound(len.begin(),len.end(),pos+1)-len.begin();
    int y=upper_bound(len.begin(),len.end(),pos+1)-len.begin();

    ll ans=0;
    int e=(len.size()-x)*9+j;
    for(int s=digit[pos];s<=e;s+=10){
        if(s<j) continue;
        ans=(ans+f[s-j][len.size()-y][y-x]*dfs(pos+1,s/10))%mod;
    }

    return dp[pos][j]=ans;
}

int main()
{
    for(int x=0;x<50;x++)
        f[0][x][0]=1;

    for(int s=1;s<500;s++){
        for(int x=0;x<50;x++)
        for(int y=0;y<50;y++){
            if(x*9+y*9<s) continue;
            if(x){
                for(int i=0;i<=9;i++){
                    if(s>=i) f[s][x][y]=(f[s][x][y]+f[s-i][x-1][y])%mod;
                }
            }else{
                for(int i=1;i<=9;i++){
                    if(s>=i) f[s][x][y]=(f[s][x][y]+f[s-i][x][y-1])%mod;
                }
            }
        }
    }

    //cout<<f[2][0][1]<<endl;
    while(scanf("%s",&s)!=EOF){
        int nn=strlen(s);
        int sum=0;
        len.clear();
        for(int i=0;i<nn;i++){
            if(s[i]=='+' || s[i]=='='){
                len.pb(sum);
                sum=0;
            }else sum++;
        }
        t=0;
        for(int i=nn-1;s[i]!='=';i--)
            digit[t++]=s[i]-'0';
        sort(len.begin(),len.end());

        //for(int i=0;i<len.size();i++) cout<<len[i]<<endl;

        if(*len.rbegin()>t){
            cout<<0<<endl;
            continue;
        }
        // cout<<*len.rbegin()<<endl;
        // cout<<t<<" "<<n<<" "<<m<<endl;
        // for(int i=0;i<t;i++) cout<<digit[i]<<endl;
        mem(dp,-1);
        ll ans=dfs(0,0);
        cout<<ans<<endl;
    }
}

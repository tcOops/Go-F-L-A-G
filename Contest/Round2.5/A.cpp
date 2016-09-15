#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100100
#define mod 998244353
using namespace std;
typedef long long ll;
int t;
int n,m;
ll factor[N<<1];
ll invfactor[N<<1];
ll get_inv(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1)ret=(ret*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return ret;
}
void init_factor()
{
    factor[0]=1,factor[1]=1,invfactor[1]=1,invfactor[0]=1;
    for(int i=2;i<=200000;i++)
    {
        factor[i]=(factor[i-1]*i)%mod;
        invfactor[i]=get_inv(factor[i],mod-2);
    }
}
ll get_C(int n,int m)
{
    if(m==0)return 1;
    return factor[n]*invfactor[m]%mod*invfactor[n-m]%mod;
}
ll get_ans(int n,int m)
{
    //x1+x2+x3+..+xm==n
    //x1最大
    ll ret=0;
    if(n==0)return 0;
    if(n==1)return 1;
    if(m==1)return 1;
    for(int i=n;i>0;i--)
    {
        if(i<=(n-i)/(m-1)+((n-i)%(m-1)==0?0:1))break;
        int tmpn=n-i,tmpm=m-1;
        ll ans=0;
        for(int j=0;j<=tmpm&&j*i<=tmpn;j++)
        {
            ll caltmp=get_C(tmpm,j)*get_C(tmpn-j*i+tmpm-1,tmpm-1)%mod;
            if(j%2==0)ans=(ans+caltmp)%mod;
            else ans=((ans-caltmp)%mod+mod)%mod;
        }
        ret=(ret+ans)%mod;
    }
    return ret*m%mod;
}
int main()
{
    init_factor();

        scanf("%d%d",&n,&m);
        printf("%lld\n",get_ans(n,m));

}

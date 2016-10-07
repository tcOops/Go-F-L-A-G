//http://hihocoder.com/contest/hiho89/problem/1

#include<cstdio>
#include<cstring>
typedef long long  ll;
const int N = 1000;
bool isPrime[N];
int prime[N];
ll n, ans;
int ans_;

void eular(){
    memset(isPrime, true, sizeof(isPrime));
    int cnt = 0;
    for(int i = 2; i < 1000; ++i){
        if(isPrime[i]){
            prime[cnt++] = i;
        }
        for(int j = 0; j < cnt && i*prime[j] < 1000; ++j){
            isPrime[i*prime[j]] = false;
            if(i%prime[j] == 0) break;
        }
    }
}

void solve(ll mul, int curPrime, int lastPrimeCnt, int totPrime){
    if(mul > n) return ;
    
    if(totPrime > ans_ || (totPrime == ans_ && mul < ans)){
        ans = mul;
        ans_ = totPrime;
    }

    ll tmp = 1;
    for(int i = 1; i <= lastPrimeCnt && (mul*tmp <= n); ++i){
        tmp *= prime[curPrime];
        solve(mul*tmp, curPrime+1, i, totPrime*(i+1));
    }
}

int main(){
    scanf("%lld", &n);
    eular();
    ans_ = 0, ans = 0;
    solve(1, 0, 200, 1);
    printf("%lld\n", ans);
    return 0;
}
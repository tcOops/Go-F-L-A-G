#include<cstdio>
#include<cstring>
using namespace std;
bool isPrime[1000010];
int prime[100010];

int main(){
    int n;
    scanf("%d", &n);
    
    int ans = 0;
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i <= n; ++i){
        if(isPrime[i]){
            prime[ans++] = i;
        }
        
        for(int j = 0; j < ans && i*prime[j] <= n; ++j){
            isPrime[prime[j]*i] = false;
            if(!(i%prime[j])) break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
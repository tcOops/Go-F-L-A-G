#include <cstdio>
#include <cstring>

void extend_gcd(long long a, long long b, long long &d, long long &x, long long &y) {
    if(!b) {
        d = a;
        x = 1, y = 0;
    }
    else {
        extend_gcd(b, a%b, d, y, x);
        y -= x*(a/b);
    }
}

int main() {
    long long s1, s2, v1, v2, m;
    scanf("%lld %lld %lld %lld %lld", &s1, &s2, &v1, &v2, &m);
    long long d, x, y;
    
    //printf("%d %d %d ", d, x, y);
    if(v1 == v2){
        if(s1 == s2){
            printf("0\n");
        }
        else{
            printf("-1\n");
        }
        return 0;
    }
    
    extend_gcd(v2-v1, m, d, x, y);

    if((s1 - s2) % d != 0) {
        printf("-1\n");
    }
    else {
        long long ans = x * (s1-s2)/d;
        if(d < 0) {
            d = -d;
        }
        if(ans >= 0){
            ans = ans - ans/(m/d)*(m/d);
        }
        else{
            long long res = -ans / (m/d);
            if(-ans % (m/d) != 0) {
                ++res;
            }
            ans += res * (m/d);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
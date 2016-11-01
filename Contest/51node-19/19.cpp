#include <cstdio>
using namespace std;
const long long MOD = 1e9 + 7;

long long fastMul(long long a, long long n) {
    long long ret = 1;
    while(n) {
        if(n & 1) {
            ret = ret * a % MOD;
        }
        n >>= 1, a = a * a % MOD;
    }
    return ret;
}

int main() {
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%lld\n", fastMul(2, c));
    return 0;
}

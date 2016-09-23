#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
const long long MOD = 1e15;

int main() {
  freopen("in.txt", "w", stdout);
  srand(time(NULL));
  for(int i = 0; i < 100; ++i) {
     long long x = rand()%MOD;
     long long y = x + rand()%(1000);
     printf("%lld %lld\n", x, y);
  }
  return 0;
}

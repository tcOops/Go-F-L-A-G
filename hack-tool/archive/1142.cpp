#include <cstdio>
#include <cmath>
#define eps 0.00000001
using namespace std;

double cal(int a, int b, int c, double x, int x0, int y0) {
    double dist = (x-x0)*(x-x0);
    double tmp = a*x*x + b*x + c - y0;
    dist += tmp*tmp;
    return dist;
}

int main() {
    int a, b, c, x, y;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    
    double l = -200.0, r = 200.0;
    while(fabs(l - r) > eps) {
      //  printf("%lf %lf\n", l, r);
        double mid = l + ((r-l)/2);
        double rmid = mid + ((r-mid)/2);
        double vmid = cal(a, b, c, mid, x, y), vrmid = cal(a, b, c, rmid, x, y);
        if(vmid < vrmid) {
            r = rmid;
        }
        else {
            l = mid;
        }
    }
    
    double res = cal(a, b, c, l, x, y);
   // printf("fff %lf %d\n", l, res);
    printf("%.3lf\n", sqrt(res));
    return 0;
}
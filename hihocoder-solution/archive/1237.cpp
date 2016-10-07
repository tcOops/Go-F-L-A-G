//提交地址: http://acm.hdu.edu.cn/showproblem.php?pid=1505
//DP经典题

#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
double x, y, r;

int main(){
    scanf("%lf%lf%lf", &x, &y, &r);
    double maxx = r + x, minx = x - r;
    int maxintX, minintX;
    double ans = 0.0;
    int ansx, ansy;
    maxintX = floor(maxx), minintX = ceil(minx);
    
    for(int i = maxintX; i >= minintX; --i){
        double resx = ((double)i - x) * ((double)i - x);
        double tmp = r*r - resx;
        double tmp3 = sqrt(tmp);
        double tmp1 = tmp3 + y, tmp2 = y - tmp3;
        int tmp4 = floor(tmp1), tmp5 = ceil(tmp2);
        // printf("%lf %lf\n", tmp4, tmp5);
        double ans1 = (tmp4-y)*(tmp4-y), ans2 = (tmp5-y)*(tmp5-y);
        double res, tmpy;
        if(ans1 >= ans2){
            res = ans1 + resx;
            tmpy = tmp4;
        }
        else{
            res = ans2 + resx;
            tmpy = tmp5;
        }
        if(res > ans){
            ans = res;
            ansx = i, ansy = tmpy;
        }
    }
    printf("%d %d\n", ansx, ansy);
    return 0;
}
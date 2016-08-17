#include<iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const double eps = 1e-7;
double x, y, r, rsquare;
int ans_x, ans_y;
double max_ans;

double dist(double x1, double y1, double x2, double y2)
{
    return (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);
}

void calc()
{
    int right = floor(x + r);
    int left = ceil(x-r);
    
    max_ans = 0;
    for(int i = right; i >= left; i --) {
        double p = y + sqrt(r * r - (i-x) * (i-x));
        int ty = floor(p);
        double dis = dist(i*1.0, ty*1.0, x, y);
        if(dis > max_ans) {
            ans_x = i;
            ans_y = ty;
            max_ans = dis;
        }
        p = y - sqrt(r * r - (i-x) * (i-x));
        ty = ceil(p);
        dis = dist(i*1.0, ty*1.0, x, y);
        if(dis > max_ans) {
            ans_x = i;
            ans_y = ty;
            max_ans = dis;
        }
    }
    cout << ans_x << " " << ans_y << endl;
}

int main()
{
    cin >> x >> y >> r;
    calc();
    
    return 0;
}

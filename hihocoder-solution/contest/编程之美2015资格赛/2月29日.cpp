#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string m1, m2;
char s[20];
const string month[12] = {"January", "February", "March", "April",
 "May", "June", "July", "August", "September", "October", "November" , "December"};

bool judge(int x){
    if(x%100 != 0 && x%4 == 0) return 1;
    if(x%400 == 0) return 1;
    return 0;
 }

 int main(){
    int n;
    int y1, d1, y2, d2;
    int m1_, m2_;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int ans = 0;

        //Parse the first year
        scanf("%s %d, %d", &s, &d1, &y1);
        m1 = s;
        for(int j = 0; j < 12; ++j){
            if(m1 == month[j]){
                m1_ = j;
            }
        }

        //Parse the second year
        scanf("%s %d, %d", &s, &d2, &y2);
        m2 = s;
        for(int j = 0; j < 12; ++j){
            if(m2 == month[j]){
                m2_ = j;
            }
        }

        for(int j = y1+1; j < y2; ++j){
            if(judge(j)){
                ++ans;
            }
        }

        bool flag1 = false, flag2 = false;
        if(m1_ == 1 && d1 == 29 || (m1_ == 0)){
            flag1 = true;
        }
        if(m2_ == 1 && d2 == 29 || (m2_ > 1)){
            flag2 = true;
        }
        if(flag1 && flag2){
            ans += (y1 == y2 ? 1 : 2);
        }
        else if(flag1){
            if(y1 != y2){
                ans += 1;
            }
        }
        else if(flag2){
            if(y1 != y2){
                ans += 1;
            }
        }
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
 }



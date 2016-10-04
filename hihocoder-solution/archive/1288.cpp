#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[3010];
int n, p, w, h;

int pages(int per){
    int lines = 0;
    int aline = w/per;
    for(int i = 0; i < n; ++i){
        lines += a[i]/aline;
        if(a[i]%aline != 0){
            ++lines;
        }
    }
    
    int ll = h/per;
    int pcnt = lines/ll;
    if(lines % ll != 0){
        ++pcnt;
    }
    return pcnt;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &n, &p, &w, &h);
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        
        int min = w;
        if(w > h){
            min = h;
        }
        int l = 1, r = min;
        int mid;
        while(l < r){
            mid = (l+r+1) >> 1;
            int tmp = pages(mid);
          //  printf("%d %d %d %d\n", l, r, mid, tmp);
            if(tmp > p){
                r = mid - 1;
            }
            else{
                l = mid;
            }
        }
        printf("%d\n", l);
    }
    return 0;
}



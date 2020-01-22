#include <cstdio>
using namespace std;
int main(){
    int n,m;
    int maxL = 0;
    int g[100002];
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &g[i]);
        if (g[i]> maxL) maxL = g[i];
    }
    int lo = maxL, hi = m*10000;
    int res = 0;
    while(lo<=hi){
        int cnt = 1;
        int mid = (lo+hi)/2;
        int tempM = mid;
        for(int i = 0;i<n;i++){
            if (tempM-g[i]<0){
                cnt++;
                tempM= mid;
            }
            tempM-=g[i];
        }
        if(cnt<=m) hi = mid-1;
        else lo=mid+1;
    }
    printf("%d", lo);
    return 0;
}
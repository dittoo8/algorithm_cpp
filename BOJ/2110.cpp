#include <cstdio>
#include <algorithm>

using namespace std;
long long h[200002];
int n,c;
int main(){
    long long lo,hi;
    scanf("%d %d", &n, &c);
    for(int i=0;i<n;i++){
        scanf("%lld", &h[i]);
    }
    sort(h,h+n);
    lo = 1;
    hi = h[n-1] - h[0];
    long long ans = 0;
    while(lo<=hi){
        int cnt = 1;
        long long mid = (lo+hi)/2;
        // printf("mid : %lld\n", mid);
        long long temp = h[0];
        for(int i=1;i<n;i++){
            // printf("cnt : %lld\n", cnt);
            if(h[i]-temp>=mid){
                cnt++;
                temp = h[i];

            }
        }
        if(cnt >= c){
            ans = max(ans,mid);
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    printf("%lld", ans);

    return 0;
}
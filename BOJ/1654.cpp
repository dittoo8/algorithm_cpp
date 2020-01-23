#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
long long k,n;
long long r[10002];
int main(){
    long long hi = 0,lo = 1;
    long long ans = 0;
    scanf("%lld %lld", &k ,&n);
    for(int i=0;i<k;i++){
        scanf("%lld", &r[i]);
        if (r[i] > hi) hi = r[i];
    }
    long long mid;
    while(lo<=hi){
        mid = (lo+hi) >> 1;
        long long temp = 0;
        for(long long i=0;i<k;i++){
            temp += r[i]/mid;
        }

        if(temp >= n){
            ans = max(ans, mid);
            lo = mid + 1;
        } else {
            hi = mid-1;
        }
    }
    printf("%lld", ans);
    return 0;
}
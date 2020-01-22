#include <cstdio>
using namespace std;
int main(){
    long long m;
    int n;
    int b[10002];
    int maxB = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &b[i]);
        if (b[i]>maxB) maxB = b[i];
    }
    scanf("%lld", &m);
    int lo = 0, hi = maxB;
    int res;
    while(lo<=hi){
        long long sum = 0;
        int mid = (lo+hi)/2;
        for(int i=0;i<n;i++){
            if(b[i]>=mid) sum+=mid;
            else {
                sum+=b[i];
            }
        }
        if(sum <= m){
            //예산이 초과되지 않았을 경우 res에 저장
            res = mid;
            lo = mid+1;
        } else {
            hi = mid -1;
        }
    }
    printf("%d", res);
    return 0;
}
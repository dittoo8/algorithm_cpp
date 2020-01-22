#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    int c[100002];
    int lo = 0;
    int hi = 0;
    scanf("%d %d",&n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &c[i]);
        lo = max(lo, c[i]);
        hi += c[i];
        //전체를 만족하는 최대값은 전체 사용 금액의 합
    }
    
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int cnt = 1;
        int now = mid;
        for(int i=0;i<n;i++){
            if (now < c[i]){
                cnt++;
                //출금횟수
                now = mid;
                //현재 가진돈
            }
            now -= c[i];
            // printf("%d %d\n",i,now);
        }
        if(cnt <= m){
            hi = mid -1;
        } else lo = mid + 1;
    }
    printf("%d", lo);
    return 0;
}
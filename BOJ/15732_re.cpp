#include <cstdio>
#include <vector>
#define MAX 1000000000
using namespace std;
long long d;
int  n,k;
struct rule{
    int s,e,d;
};
int main(){
    vector<rule> v;
    scanf("%d %d %lld", &n ,&k, &d);
    v.resize(k);
    for(int i=0;i<k;i++){
        long long s,e,d;
        scanf("%d %d %d", &v[i].s, &v[i].e, &v[i].d);
    }
    int lo = 0, hi = MAX;
    while(lo<=hi){
        long long tcnt = 0;
        int mid = (hi+lo)/2; // 현재 LOOP에서 마지막 도토리의 방
        for(int i=0;i<k;i++){
            if(tcnt>=d) break;
            //마지막 도토리 위치보다 시작점이 큰 규칙은 continue
            if (v[i].s > mid) continue;
            if (v[i].e > mid){
                //끝나는 위치가 마지막 도토리의 위치보다 큰 경우
                tcnt+=(mid-v[i].s)/v[i].d + 1;
            }else {
                //현재 규칙의 모든 위치를 포함하는 경우
                tcnt+=(v[i].e-v[i].s)/v[i].d +1;
            }
        }
        if (tcnt >= d) hi = mid-1;
        else lo = mid+1;
    }
    printf("%d\n",lo);
    return 0;
}
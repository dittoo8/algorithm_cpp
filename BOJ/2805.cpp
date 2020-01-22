#include <cstdio>
using namespace std;
long long n,m;
long long t[1000002];
int main(){
    scanf("%lld %lld", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%lld", &t[i]);
    }
    int lo = 0, hi = 1000000000;
    while(lo+1< hi){
        long long sum = 0;
        int mid = (lo+hi)/2;
        for(int i=0;i<n;i++){
            if(t[i]>mid) sum+=t[i] - mid;
        }
        if(sum>= m) lo = mid;
            else hi = mid;
    }
    printf("%d\n", lo);
    return 0;

}
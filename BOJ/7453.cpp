#include <cstdio>
#include <algorithm>
#define MAX 4001
using namespace std;
int n,k;
long long a[MAX], b[MAX], c[MAX],d[MAX],res;
long long mid1[16000001], mid2[16000001];
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld %lld %lld",&a[i], &b[i], &c[i], &d[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mid1[k]=a[i]+b[j];
            mid2[k]=c[i]+d[j];
            k++;
        }
    }
    sort(mid1,mid1+k);
    sort(mid2,mid2+k);
    for(int i=0;i<k;i++){
        res+=(upper_bound(mid1,mid1+k,-mid2[i])-lower_bound(mid1,mid1+k,-mid2[i]));
    }
    printf("%lld\n", res);
    return 0;
}
#include <cstdio>
using namespace std;
int main(){
    int tc,n;
    long long a[101]={0,};
    a[1]= a[2]=a[3]=1;
    a[4]=a[5]=2;
    scanf("%d", &tc);
    for(int i=6;i<=100;i++){
        a[i]=a[i-1]+a[i-5];
    }
    while(tc--){
        scanf("%d", &n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
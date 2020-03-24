#include <cstdio>
#include <algorithm>
#define MOD 1000000007
using namespace std;
long long c[2501];
int main(){
    int t,l;
    c[0]= 1;
    for(int i=0;i<2500;i++){
        for(int j=0;j<=i;j++){
            c[i+1]+=c[j]*c[i-j];
            c[i+1]%=MOD;
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&l);
        l%2 == 0 ? printf("%lld\n", c[l/2]) : puts("0");
    }
    return 0;
}
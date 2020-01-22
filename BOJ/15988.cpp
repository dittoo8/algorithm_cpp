#include <cstdio>
using namespace std;
long long d[1000002];
int n,m;
long long dp(int x){
    if (x==1) return d[1] = 1;
    if (x==2) return d[2] = 2;
    if (x==3) return d[3] = 4;
    if(d[x]!=0) return d[x];
    return d[x] = (dp(x-1)+ dp(x-2) + dp(x-3))%1000000009;
}
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        printf("%lld\n", dp(m));
    }
    return 0;
}
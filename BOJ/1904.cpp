#include <cstdio>
using namespace std;
long long d[1000002] = {0,};
long long dp(int n){
    if (n==1) return 1;
    if (n==2) return 2;
    if(d[n]!=0) return d[n];
    return d[n] = (dp(n-1)+dp(n-2))%15746;
}
int main(){
    long long n;
    scanf("%lld", &n);
    printf("%lld", dp(n));
}
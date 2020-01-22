#include <cstdio>
using namespace std;
int n,k;
long long d[1002][1002];
long long dp(int n, int r){
    if(n==r || r ==0) return 1;
    if(d[n][r]!=0) return d[n][r];
    return d[n][r] = (dp(n-1,r-1) + dp(n-1,r))%10007;

}
int main(){
    scanf("%d %d", &n, &k);
    printf("%lld\n", dp(n,k)%10007);
    return 0;
}
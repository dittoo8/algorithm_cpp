#include <cstdio>
using namespace std;
int t,n;
// int res[2] = {0,};
int dp[41][2];
int fib(int n){
    if (n==0) { dp[n][0]++; return 0; }
    else if (n==1) { dp[n][1]++; return 1; }
    else if (!(dp[n][0] == 0 && dp[n][1] == 0))
        return fib(n-1) + fib(n-2); }
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        fib(n);
        printf("%d %d\n", dp[n][0], dp[n][1]);
    }

}
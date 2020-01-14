#include <cstdio>
using namespace std;
int n, sum;
int dp[10002][10];
int main(){
    sum = 0;
    scanf("%d", &n);
    for(int i=0;i<=9;i++) dp[1][i] = 1;

    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][0];
        for(int j=1;j<=9;j++){
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007;
        }
    }
    for(int i=0;i<=9;i++){
        sum = (sum + dp[n][i])%10007;
    }
    printf("%d", sum);
    return 0;
}
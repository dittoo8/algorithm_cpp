#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int dp[100002];
int main(){
    scanf("%d", &n);
    for (int i = 0;i<=n;i++){
        dp[i] = i;
    }
    for(int i=1;i<=sqrt(n);i++){
        for(int j=i*i;j<=n;j++){
            dp[j] = min(dp[j], dp[j-i*i] + 1);
        }
    }
    printf("%d", dp[n]);
    return 0;
}
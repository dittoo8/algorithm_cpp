#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int p[10002];
int dp[1002];
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &p[i]);
    }
    for (int i = 1; i<=n; i++){
        dp[i] = p[1]*i;
    }

    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            if (i >= j) {
            dp[i] = max(dp[i],dp[i-j]+p[j]);
            }
        }
    }
    printf("%d", dp[n]);

}
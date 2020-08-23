#include <cstdio>
using namespace std;
#define MOD 10007
int main() {
    int N, K, i, j;
    scanf("%d %d", &N, &K);
    int dp[N+1][K+1];
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= K; j++) {
            if (i == j || j == 0) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i-1][j-1] % MOD) + (dp[i-1][j] % MOD);
                dp[i][j] %= MOD;
            }
        }
    }
    printf("%d\n", dp[N][K]);
    return 0;
}
#include<iostream>
#define MOD 1000000000
using namespace std;
long long dp[201][201];
int main() {

    int n,k;
    cin >> n >> k;
    for(int i = 0; i <= n; i++) {
         dp[i][1] = 1;
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 2; j<= k; j++) {
            for(int k = 0 ; k<= i; k++) {
                dp[i][j] += dp[i-k][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}

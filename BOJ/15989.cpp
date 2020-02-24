#include <iostream>
using namespace std;
int dp[2][10001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[0][2] = 1;
    for (int i = 3; i <= 10000; i++) {
        dp[0][i] = dp[0][i - 2] + 1;
        dp[1][i] = dp[0][i - 3] + dp[1][i - 3] + 1;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << 1+dp[0][n]+dp[1][n] << '\n';
    }
    return 0;
}
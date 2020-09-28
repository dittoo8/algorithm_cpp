#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e6;
const int PRD = 15e5;
long long dp[PRD];
long long fibo(int k) {
	if (k <= 1) return k;
	long long& ret = dp[k];
	if (ret != -1) return ret;
	return ret = (fibo(k - 1) + fibo(k - 2))%MOD;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	long long n;
    cin >> n;
	fill(dp, dp + PRD, -1);
	cout << fibo(n%PRD) << '\n';
}
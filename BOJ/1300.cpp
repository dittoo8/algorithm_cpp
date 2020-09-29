#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n, k;
	cin >> n >> k;

	int low = 1;
	int high = k;
	int ret = -1;
	while (low <= high){
		int mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			cnt += min(mid / i, n);
		}
		if (cnt < k) {
			low = mid + 1;
		}else {
			ret = mid;
			high = mid - 1;
		}
	}
	cout << ret << "\n";
    return 0;
}
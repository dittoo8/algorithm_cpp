#include <iostream>
using namespace std;
int arr[2000];
bool d[2000][2000];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	// 거리가 1 or 2 인 값들을 구한다.
	for (int i = 1; i <= n; i++) {
		d[i][i] = true;
		if (i < n && arr[i] == arr[i + 1]) d[i][i + 1] = true;

	}
	// 거리가 3 이상인 값들을 구한다.
	for (int k = 2; k < n; k++) {
		for (int i = 1; i <= n - k; i++) {
			int j = i + k;
			if (arr[i] == arr[j] && d[i + 1][j - 1])
				d[i][j] = true;
		}
	}
	int k; 
	cin >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		cout << d[x][y] << '\n';
	}
	return 0;
}
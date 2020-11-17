#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int arr[201][201];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int N,M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
            if(i == j) arr[i][j] = 1;
		}
	}
	vector<int> trip;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		trip.push_back(x-1);
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][k] == 1 && arr[k][j] == 1) arr[i][j] = 1;
			}
		}
	}
	bool flag = true;
	for (int i = 0; i < trip.size()-1; i++) {
		if (arr[trip[i]][trip[i + 1]] != 1) flag = false;
	}
	if (flag) cout << "YES" <<'\n';
	else cout << "NO" << '\n';
	return 0;
}
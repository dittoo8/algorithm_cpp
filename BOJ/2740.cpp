#include <iostream>
#define MAX 101
using namespace std;
int pro1[MAX][MAX], pro2[MAX][MAX], res[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin>>pro1[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> pro2[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				res[i][j] += pro1[i][k] * pro2[k][j];
			}
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
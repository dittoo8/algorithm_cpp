#include<cstdio>
#include<algorithm>
using namespace std;
int a[300][300];
int n, m, r;
void rotate(int k, int r) {
	while (r--) {
		for (int t = 0; t < k; t++) {
			int temp = a[t][t];
			for (int j = t + 1; j < m - t; j++) a[t][j - 1] = a[t][j]; //->
			for (int i = t + 1; i < n - t; i++) a[i - 1][m - t - 1] = a[i][m - t - 1]; // V
			for (int j = m - t - 2; j >= t; j--) a[n - t - 1][j + 1] = a[n - t - 1][j]; // <-
			for (int i = n - t - 2; i > t; i--) a[i + 1][t] = a[i][t]; // ^
			a[t + 1][t] = temp;
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &r);
	int k = min(n, m)/2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
	}
	rotate(k, r);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
            printf("%d ", a[i][j]);
        }
		printf("\n");
	}
}
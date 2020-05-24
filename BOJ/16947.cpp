#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<int> mat[3001];
int check[3001];
int dist[3001];
int go(int x, int p) {
	if (check[x]) { // 부모정보 반환
		return x;
	}
	check[x] = 1;
	for (int k = 0; k < mat[x].size(); k++) {
		int y = mat[x][k];
		if (y == p) continue;     // 서로 지목하는 경우에 대해서는 배제
		int ret = go(y, x);
		if (ret == -2) return -2; // 사이클이 포함되어 있지 않은 노드라면
		if (ret >= 0) {
			check[x] = 2;             // 사이클
			if (ret == x) return -2;  // 시작점
			else return ret;          // 사이클이면서 시작점이 아닐 때
		}
	}
	return -1; // 리프 노드일 때
}
int main(void) {
	int n;
    scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
        scanf("%d %d", &x, &y);
		mat[x].push_back(y);
		mat[y].push_back(x);
	}
	go(1, -1);
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (check[i] == 2) {
			dist[i] = 0;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < mat[x].size(); i++) {
			int y = mat[x][i];
			if (check[y] == 2) continue;
			check[y] = 2;
			dist[y] = dist[x] + 1;
			q.push(y);
		}
	}
	for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
	}
    printf("\n");
	return 0;
}
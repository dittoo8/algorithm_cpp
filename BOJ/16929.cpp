#include <iostream>
#include <cstring>
using namespace std;
int n, m,si,sj;
char map[51][51];
bool visit[51][51],suc;
const int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

void dfs(int dep, int x, int y) {
	if (suc) return;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (map[nx][ny] != map[si][sj]) continue;
		if (visit[nx][ny]) {
			if (dep >= 4 && si == nx && sj == ny) {
				suc = true;
				return;
			}
		}else {
			visit[nx][ny] = true;
			dfs(dep + 1, nx, ny);
		}
	}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visit, false, sizeof(visit));
			si=i,sj=j;
			visit[i][j] = true;
			dfs(1, i, j);
			if (suc) break;
		}
	}
	if (suc) cout << "Yes" <<endl;
	else cout << "No"<<endl;
	return 0;
}
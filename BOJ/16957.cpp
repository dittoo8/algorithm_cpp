#include <iostream>
using namespace std;
int r, c,a[500][500],parent[500 * 500],ans[500 * 500];
const int dy[8] = { -1,-1,0,1,1,1,0,-1 }, dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int findParent(int x){
	if (parent[x] == x) return x;
	else return parent[x] = findParent(parent[x]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> r >> c;
	for(int i=0; i<r; ++i){
        for (int j = 0; j < c; ++j){
			cin >> a[i][j];
		}
    }
	for(int i=0; i<r; ++i)
		for (int j = 0; j < c; ++j) {
			int y = i,x = j;
			for (int k = 0; k < 8; ++k) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (!(0 <= ny && ny < r && 0 <= nx && nx < c)) continue;
				if (a[y][x] > a[ny][nx]) {
					y = ny;
					x = nx;
				}
			}
			parent[i*c + j] = y * c + x;
		}

	for(int i=0; i<r; ++i){
        for (int j = 0; j < c; ++j) {
			ans[findParent(i*c + j)] += 1;
		}
    }
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << ans[i*c + j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
#include<iostream>
using namespace std;
#define MAX 500
int map[MAX][MAX],block[MAX];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int h, w, ret;
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> block[i];
		if (block[i] == 0) continue;
		int cnt = 0;
		for (int j = h - 1; ; j--) {
			map[j][i] = 1;
			cnt++;
			if (cnt == block[i]) break;
		}
	}
	ret = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1) continue;
			//왼쪽
			int xp, yp;
			bool left, right;
			left = right = false;
			xp = i;
			yp = j;
			while (true) {
				yp -= 1;
				if (yp < 0) break;
				if (map[xp][yp] == 1) {
					left = true;
					break;
				}
			}
			xp = i, yp = j;
			//오른쪽
			while (true) {
				yp += 1;
				if (w <= yp) break;
				if (map[xp][yp] == 1) {
					right = true;
					break;
				}
			}
			if (left && right) ret++;
		}
	}
	cout << ret;
	return 0;
}
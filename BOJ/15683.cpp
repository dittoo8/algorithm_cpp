#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int a[9][9];
int visited[9][9];
vector<pair<int, int>> v;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int best = 987654321;
void check(int y, int x, int i, int num){
	int ny = y ;
	int nx = x ;
	while (1) {
		ny += dy[i];
		nx += dx[i];
		if (a[ny][nx] == 6) break;
        if(ny <0 || ny >=n || nx <0 || nx>=m) break;
		visited[ny][nx] += num;
	}
}
void rotate(int s, int i, int num){
	int y = v[s].first;
	int x = v[s].second;
	int number = a[y][x];
	if (number == 1){
		check(y, x, (i+1)%4, num);
	}else if (number == 2){
		check(y, x, (i + 1)%4, num);
		check(y, x, (i + 3) % 4, num);
	}else if (number == 3){
		check(y, x, (i + 1) % 4, num);
		check(y, x, (i + 0) % 4, num);
	}else if (number == 4){
		check(y, x, (i + 1) % 4, num);
		check(y, x, (i + 0) % 4, num);
		check(y, x, (i + 3) % 4, num);
	}else if (number == 5) {
		check(y, x, (i + 1) % 4, num);
		check(y, x, (i + 0) % 4, num);
		check(y, x, (i + 3) % 4, num);
		check(y, x, (i + 2) % 4, num);
	}
}
void solve(int s) {
	if (s > (int)v.size() - 1) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (visited[i][j] == 0) cnt++;
			}
		}
		best = min(best, cnt);
		return;
	}
	for (int i = 0; i < 4; ++i){
		rotate(s, i, 1);
		solve(s + 1);
		rotate(s, i, -1);
	}
}
int main(){
    scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
            scanf("%1d",&a[i][j]);
			if (a[i][j] != 0 && a[i][j] != 6){
				v.push_back({ i,j });
				visited[i][j] = a[i][j];
			}else if (a[i][j] == 6) visited[i][j] = 6;
		}
	}
	if ((int)v.size() == 0){
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i][j] == 0)
					cnt++;
        printf("%d\n", cnt);
		return 0;
	}else {
		solve(0);
        printf("%d\n",best);
	}
	return 0;
}
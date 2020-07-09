#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
string a[8];
const int dy[] = { -1,0,1,1,1,0,-1,-1,0 }, dx[] = { 1,1,1,0,-1,-1,-1,0,0 };
bool check[9][8][8];
struct pos {
    int t,x,y;
};
int main(){
	for (int i = 0; i < 8;i++){
        cin >> a[i];
    }
	queue<pos> q;
	q.push({ 0,7,0 }); //t,x,y
	check[0][7][0] = true;
	while (!q.empty()) {
        int t = q.front().t;
        int x = q.front().x;
        int y = q.front().y;
		q.pop();
		if (x == 0 && y == 7) {
            cout << 1 << '\n';
            return 0;
        }
		for (int i = 0; i < 9; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nt = min(t + 1, 8);
            //범위 벗어남
            if(nx <0 || nx >= 8 || ny <0 || ny>=8) continue;
			// 벽이라서 못갈때
			if (nx - t >= 0 && a[nx - t][ny] == '#') continue;
			// 내려올 벽이 닿았을때
			if (nx - t - 1 >= 0 && a[nx - t - 1][ny] == '#') continue;
			if (!check[nt][nx][ny]) {
				check[nt][nx][ny] = true;
				q.push({ nt,nx,ny,});
			}

		}
	}
    cout << 0 << "\n";
	return 0;
}
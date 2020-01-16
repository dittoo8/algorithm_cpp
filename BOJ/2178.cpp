#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
int n,m;
int map[102][102];
const int dx[] = {-1, 1, 0,0}, dy[] = {0,0,-1,1};
void bfs(){
    queue<pair<int, int> > q;
    q.push(make_pair(1,1));
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(x == n && y == m) {
            printf("%d", map[n][m]);
            break;
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<1 || nx>n || ny<1 ||ny>m) continue;
            if(map[nx][ny] > 0 && map[nx][ny] <= map[x][y]) {
                //0이면 갈 수 없는 곳, 그리고 현재 위치보다 작은수여야 방문 안한 곳
                map[nx][ny] = map[x][y] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    bfs();
    return 0;
}
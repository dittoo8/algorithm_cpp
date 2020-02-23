#include <cstdio>
#include <deque>
using namespace std;
int m, n;
int a[101][101];
int dist[101][101];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int bfs() {
    deque<pair<int, int> > dq;
    dq.push_back(make_pair(1, 1));
    a[1][1] = -1;
    while (!dq.empty()) {
        int x = dq.back().first, y = dq.back().second;
        dq.pop_back();
        for (int i=0; i<4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (a[nx][ny] == -1) continue;
            else if (a[nx][ny] == 0) {
                dq.push_back(make_pair(nx, ny));
                dist[nx][ny] = dist[x][y];
            } else {
                dq.push_front(make_pair(nx, ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
            a[nx][ny] = -1;
        }
    }
    return dist[n][m];
}
int main() {
    scanf("%d %d", &m, &n);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    printf("%d\n", bfs());
    return 0;
}
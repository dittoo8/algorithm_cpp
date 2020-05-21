#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int dx[] = { -2,-2,0,0,2,2 },dy[] = { -1,1,-2,2,-1,1 };
int d[201][201];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int fx, fy, ex, ey;
    cin >> fx >> fy >> ex >> ey;
    memset(d, -1, sizeof(d));
    queue<pair<int, int>> q;
    q.push({ fx,fy });
    d[fx][fy] = 0;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 6; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!(0 <= ny && ny < n && 0 <= nx && nx < n)) continue;
            if (d[nx][ny] == -1) {
                d[nx][ny] = d[x][y] + 1;
                q.push({ nx,ny });
            }
         }
    }
    if (d[ex][ey] == -1) cout << -1 << "\n";
    else cout << d[ex][ey] << "\n";
    return 0;
}
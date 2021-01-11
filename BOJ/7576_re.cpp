#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;
const int dx[] ={ -1,1,0,0}, dy[] = {0,0,-1,1};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m,cnt=0;
    int maps[MAX][MAX];
    cin >> m >> n;
    queue<pair<int, int> > q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> maps[i][j];
            if (maps[i][j]==1) {
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx >= n || ny <0 || ny >=m) continue;
            if(maps[nx][ny]==0){
                q.push(make_pair(nx,ny));
                maps[nx][ny] = maps[x][y]+1;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]==0){
                cout << -1 << '\n';
                return 0;
            }else if(maps[i][j]>ans) ans = maps[i][j];
        }
    }
    cout << ans-1 << '\n';
    return 0;
}
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
int a[10][10],dist[10][10][20];
const int dx[]={0,0,-1,1}, dy[]={-1,1,0,0};
struct pos {
    int x,y,t;
};
int bfs(){
    memset(dist,-1,sizeof(dist));
    queue<pos> q;
    q.push({0,0,0});
    dist[0][0][0] = 0;
    while(!q.empty()){
        int x = q.front().x, y = q.front().y;
        int t = q.front().t; q.pop();
        if (a[x][y]>= 2 && t % a[x][y] !=0){
            // 오작교 위에서 기다림
            int nt = (t+1)%a[x][y];
            if (dist[x][y][nt]==-1){
                dist[x][y][nt] = dist[x][y][t] + 1;
                q.push({x,y,nt});
            }
        } else {
            for(int k=0;k<4;k++){
                int nx = x+dx[k], ny=y+dy[k];
                if (nx <0 || nx >=n || ny <0 || ny >=n) continue;
                if (a[x][y] >= 2 && a[nx][ny] >= 2) continue;
                if (a[nx][ny] >= 1){
                    int nt = (dist[x][y][t]+1)%a[nx][ny];
                    if (dist[nx][ny][nt]==-1){
                        dist[nx][ny][nt]=dist[x][y][t]+1;
                        q.push({nx,ny,nt});
                    }
                }
            }
        }
    }
    return dist[n-1][n-1][0];
}
bool can(int i, int j){
    bool ver = (i>=1 && i<n-1 && j>=0 &&  j<n) && a[i-1][j]==1 && a[i+1][j]==1;
    bool hor = (i>0 && i<n && j>=1 && j<n-1) && a[i][j-1]==1 && a[i][j+1]==1;
    return !(ver && hor);
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    int ans = 1000000;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (a[i][j]==0 && can(i,j)){
                a[i][j] = m;
                int now = bfs();
                if (now != -1) {
                    if (ans > now) ans = now;
                }
                a[i][j]=0;
            }
        }
    }
    if (ans == 1000000){
        cout << -1 << '\n';
    } else cout << ans << '\n';
    return 0;
}
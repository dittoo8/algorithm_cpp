#include <cstdio>
#include <queue>
using namespace std;
int n,m;
int a[1001][1001];
int dist[1001][1001][2]; //마지막 인덱스 : 벽 부쉈는지 체크:0 (안부숨), 1 (부숨) 
int dx[] = {-1,0,0,1}, dy[] = {0,1,-1,0};
int bfs(){
    queue<pair<int, pair<int, int> > > q; //wall, (x,y)
    q.push(make_pair(0,make_pair(0,0)));
    dist[0][0][0] = 1;
    while(!q.empty()){
        int wall = q.front().first;
        int nowx = q.front().second.first;
        int nowy = q.front().second.second;
        if (nowx == n-1 && nowy == m-1) return dist[nowx][nowy][wall];
        q.pop();
        for(int i=0;i<4;i++){
            int nx = nowx+dx[i], ny = nowy+dy[i];
            if (nx <0 || nx >=n||ny <0 || ny >=m) continue;
            if (wall==1 && a[nx][ny]==1) continue;
            if (dist[nx][ny][wall]) continue;
            if (a[nx][ny]==0) {
                dist[nx][ny][wall] = dist[nowx][nowy][wall]+1;
                q.push(make_pair(wall,make_pair(nx,ny)));
            } else if(a[nx][ny]==1 && wall ==0){
                dist[nx][ny][1] = dist[nowx][nowy][wall]+1;
                q.push(make_pair(1,make_pair(nx,ny)));
            }
            
        }
    }
    return -1;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &a[i][j]);
        }
    }
    printf("%d", bfs());
    return 0;
}
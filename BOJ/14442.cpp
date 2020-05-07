#include <cstdio>
#include <queue>
using namespace std;
struct map {
    int x, y, w;
};
int n,m,k, dist[1001][1001][11]; // dist (x좌표, y좌표, 벽 부순 횟수);
char a[1001][1001];
const int dx[] = {-1,0,1,0}, dy[]={0,1,0,-1};
int bfs(){
    queue<map> q;
    q.push({0,0,0});
    dist[0][0][0]= 1;
    while(!q.empty()){
        int x = q.front().x, y=q.front().y;
        int w = q.front().w; q.pop();
        if (x == n-1 && y == m-1){
            return dist[x][y][w];
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny=y+dy[i],nw = w+1;
            if (nx <0 || nx >= n || ny<0 || ny>= m) continue;
            if (dist[nx][ny][w]) continue;
            if (a[nx][ny]=='0'){
                dist[nx][ny][w] = dist[x][y][w]+1;
                q.push({nx,ny,w});
            }else if (a[nx][ny]=='1' && nw <=k){
                dist[nx][ny][nw]= dist[x][y][w]+1;
                q.push({nx,ny,nw});
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<n;i++){
        scanf("%s", a[i]);
    }
    printf("%d\n",bfs());
    return 0;
}
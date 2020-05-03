#include <cstdio>
#include <queue>
using namespace std;
struct coin {
    int x, y, a, b;
};
int n,m;
char a[22][22];
int dist[22][22][22][22];
queue<coin> q;
const int dx[] = {-1,0,0,1}, dy[] = {0,1,-1,0};
bool escape(int &x, int &y){
    return x < 1 || x > n || y <1 || y >m;
}
bool wall (int &x, int &y){
    return a[x][y]=='#';
}
void bfs(){
    while(!q.empty()){
        int x = q.front().x, y=q.front().y;
        int a = q.front().a, b= q.front().b;
        q.pop();
        if (dist[x][y][a][b]>10) break;
        if (escape (x,y) ^ escape (a, b)){
            printf("%d\n", dist[x][y][a][b]);
            return;
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];
            int na = a+dx[i], nb = b+dy[i];
            if (escape(nx,ny) && escape (na, nb)) continue;
            if (wall(nx,ny) && wall(na,nb)) continue;
            if (wall(nx,ny)) nx = x, ny = y;
            else if (wall(na,nb)) na= a, nb=b;
            if (dist[nx][ny][na][nb]) continue;
            q.push({nx,ny,na,nb});
            dist[nx][ny][na][nb] = dist[x][y][a][b]+1;
        }
    }
    printf("-1\n");
}
int main(){
    int x = -1,y;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1s", &a[i][j]);
            if (a[i][j]=='o'){
                if (x== -1) x=i, y=j;
                else q.push({x,y,i,j});
            }
        }
    }
    bfs();
    return 0;
}
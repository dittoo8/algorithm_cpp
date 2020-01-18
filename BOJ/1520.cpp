#include <cstdio>
using namespace std;
int m,n;
int map[510][510];
int d[510][510];
const int dx[] = {-1, 0,0,1}, dy[] = {0,-1,1,0};
int dp(int x, int y){
    if (d[x][y] != -1) return d[x][y];
    if (x < 1 || x >m || y <1 || y > n) return 0;
    if (x==1 && y==1) return 1;
    d[x][y] = 0;
    for(int k=0;k<4;k++){
        int nx = x+dx[k], ny = y+dy[k];
            if(map[nx][ny] > map[x][y]) {
                d[x][y]+=dp(nx,ny);
            }
    }
    return d[x][y];
}
int main(){
    scanf("%d %d", &m, &n);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &map[i][j]);
            d[i][j] = -1;
        }
    }
    d[1][1] = 1;

    printf("%d", dp(m,n));
    return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int apple[1002][1002];
int m,n;
queue<pair<int, int> > q;
const int dx[] = {-1, 1, 0,0}, dy[] = {0,0,-1,1};
void bfs(){
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (apple[nx][ny] == 0) {
                //안익은거 발견
                apple[nx][ny] = apple[x][y] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
int main(){
    scanf("%d %d", &m, &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &apple[i][j]);
            if(apple[i][j] == 1) q.push(make_pair(i,j));
        }
    }
    bfs();

    int max = apple[1][1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (apple[i][j] == 0) {
                //안익은거있을때
                printf("-1");
                return 0;
            }
            if(apple[i][j] > max){
                max = apple[i][j];
            }
        }
    }
    printf("%d\n", max-1);
    //첫날이 0날인데 1부터 시작했으니까 -1 해줌
    return 0;
}
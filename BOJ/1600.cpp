#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct monkey {
    int x, y, z;
};
int k,w,h;
int a[201][201], dist[201][201][31];
const int dx[]={-1,0,1,0,-2,-2,-1,-1,1,1,2,2};
const int dy[]={0,1,0,-1,-1,1,-2,2,-2,2,-1,1};
void bfs(){
    queue<monkey> q;
    q.push({0,0,0});
    // x, y, 말 이동횟수
    while(!q.empty()){
        int x = q.front().x, y=q.front().y,z=q.front().z;
        q.pop();
        int j = z== k? 4 :12;
        if(x == h-1 && y== w-1){
            printf("%d\n", dist[x][y][z]);
            return;
        }
        for(int i=0;i<j;i++){
            int nx = x+dx[i], ny=y+dy[i];
            int nz = i<4? z : z+1;
            if (nx <0|| nx >=h || ny <0 || ny>=w)continue;
            if(dist[nx][ny][nz] || a[nx][ny]) continue;
            dist[nx][ny][nz] = dist[x][y][z] +1;
            q.push({nx,ny,nz});
        }
    }
    printf("-1\n");
}
int main(){
    scanf("%d", &k);
    scanf("%d %d", &w, &h);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%1d", &a[i][j]);
        }
    }
    bfs();
    return 0;
}
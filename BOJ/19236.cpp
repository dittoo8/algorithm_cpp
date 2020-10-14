#include <iostream>
#include <cstring>
using namespace std;
struct fish {
    int x, y, d;
};
int m[5][5],ans;
fish f[18];
const int dx[]= {-1,-1,0,1,1,1,0,-1}, dy[]={0,-1,-1,-1,0,1,1,1};
void solve(int x, int y, int sum,int sharkD, int map[5][5], fish fi[18]){
    for(int i=1;i<=16;i++){
        int nowX = fi[i].x,nowY = fi[i].y, nowD = fi[i].d;
        if (nowX == -1) continue;
        for(int k=0;k<8;k++){
            int nx = nowX + dx[(nowD+k)%8], ny = nowY + dy[(nowD+k)%8];
            if(nx < 0 || nx >=4 || ny <0 || ny >=4) continue;
            if(map[nx][ny]==17) continue;
            if(map[nx][ny]){
                int tFish = map[nx][ny];
                fi[tFish].x = nowX;
                fi[tFish].y = nowY;
            }
            map[nowX][nowY] = map[nx][ny];
            map[nx][ny]= i;
            fi[i].x = nx;
            fi[i].y = ny;
            fi[i].d = (nowD+k)%8;
            break;
        }
    }
    map[x][y] = 0;
    bool fin = true;
    int nextX = x+dx[sharkD], nextY = y+dy[sharkD];
    while(!(nextX < 0|| nextX >= 4 | nextY< 0 || nextY>=4)){
        if(map[nextX][nextY]){
            fin = false;
            int map2[5][5];
            fish fi2[18];
            memcpy(map2,map,sizeof(map2));
            memcpy(fi2, fi,sizeof(fi2));
            int tmpFish = map2[nextX][nextY];
            fi2[tmpFish].x = -1;
            map2[nextX][nextY] = 17;
            solve(nextX,nextY,sum+tmpFish,fi[tmpFish].d,map2,fi2);
        }
        nextX+=dx[sharkD];
        nextY+=dy[sharkD];
    }
    if(fin){
        if (sum > ans) ans = sum;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int u,v;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> u >> v;
            f[u].d = v-1;
            f[u].x = i;
            f[u].y = j;
            m[i][j] = u;
        }
    }
    int init_fish = m[0][0];
    f[init_fish].x = -1;
    m[0][0] = 17;
    solve(0,0,init_fish,f[init_fish].d,m,f);
    cout << ans << '\n';
    return 0;
}
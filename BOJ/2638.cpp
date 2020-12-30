#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;
int maps[MAX][MAX],tmp[MAX][MAX],n,m;
bool ck,visit[MAX][MAX];
const int dx[] = {-1,1,0,0}, dy[]={0,0,-1,1};
void dfs(int x, int y){
    if(visit[x][y]) return;
    visit[x][y] = true;
    for(int k=0;k<4;k++){
        int nx=x+dx[k],ny=y+dy[k];
        if(nx < 0 || nx >=n || ny <0 || ny >=m )continue;
        if (visit[nx][ny]) continue;
        if(maps[nx][ny]==2){
            tmp[nx][ny]=0;
            ck = true;
        }else if (maps[nx][ny]==1){
            maps[nx][ny]=2;
        }else dfs(nx,ny);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> maps[i][j];
        }
    }
    memcpy(tmp,maps,sizeof(maps));
    for(int time=0;;time++){
        ck = false;
        dfs(0,0);
        dfs(0,m-1);
        dfs(n-1,0);
        dfs(n-1,m-1);
        memcpy(maps,tmp,sizeof(maps));
        fill(&visit[0][0],&visit[n][m]+1,0);
        if(!ck) {
            cout << time << '\n';
            break;
        }
    }
    return 0;
}
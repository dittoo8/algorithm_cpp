#include <iostream>
#include <string>
#define MAX 101
using namespace std;
const int dx[]= {0,0,-1,1}, dy[]= {-1,1,0,0};
int maps[MAX][MAX];
bool visit[MAX][MAX];
int n,m;
void dfs(int x, int y){
    visit[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx <0 || nx >= n || ny < 0 || ny>=m) continue;
        if(visit[nx][ny]) continue;
        if(maps[nx][ny]==1){
            maps[nx][ny] = 2;
        }else if(maps[nx][ny]==0 ){
            dfs(nx,ny);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cnt = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> maps[i][j];
            if(maps[i][j]==1) cnt++;
        }
    }
    int time = 1;
    while(true){
        fill(&visit[0][0], &visit[n][m]+1,0);
        for(int i=0;i<n;i++){
            if(maps[i][0]== 0 && !visit[i][0]){
                dfs(i,0);
            }
            if(maps[i][m-1]== 0 && !visit[i][m-1]){
                dfs(i,m-1);
            }
        }
        for(int i=0;i<m;i++){
            if(maps[0][i]== 0 && !visit[0][i]){
                dfs(0,i);
            }
            if(maps[n-1][i]== 0 && !visit[n-1][i]){
                dfs(n-1,i);
            }
        }
        int tmp = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (maps[i][j]== 2){
                    maps[i][j]=0;
                    tmp++;
                }

            }
        }
        if(tmp == cnt){
            break;
        }
        cnt-=tmp;
        time++;
    }
    cout << time << '\n';
    cout << cnt << '\n';
    return 0;
}
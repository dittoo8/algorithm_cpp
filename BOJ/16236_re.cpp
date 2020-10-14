#include <iostream>
#include <queue>
#define INF 100
using namespace std;
int n,shark,ans;
int map[21][21], visit[21][21];
queue<pair<int, int> > q;
const int dx[]= {0,0,-1,1}, dy[]={-1,1,0,0};
void solve(){
    int x, y;
    int movex=INF, movey = INF;
    int eatCnt = 0;
    while(!q.empty()){
        int qS = q.size();
        while(qS--){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = x+dx[k], ny = y+dy[k];
                if(nx < 0 || nx >= n || ny <0 || ny >=n) continue;
                if(visit[nx][ny]) continue;
                if (map[nx][ny]>shark) continue;
                q.push(make_pair(nx,ny));
                visit[nx][ny] = visit[x][y]+1;
                if(map[nx][ny]!=0 && map[nx][ny]< shark){
                    if(movex > nx){
                        movex = nx;
                        movey = ny;
                    }else if (movex == nx ){
                        if(movey > ny){
                            movex = nx;
                            movey = ny;
                        }
                    }
                }
            }
        }
        if(movex != INF){
            eatCnt++;
            if(eatCnt == shark){
                shark++;
                eatCnt = 0;
            }
            map[movex][movey] = 0;
            int time = visit[movex][movey];
            while(!q.empty()) q.pop();
            fill(&visit[0][0],&visit[n][n]+1,0);
            q.push(make_pair(movex,movey));
            visit[movex][movey] = time;
            ans = time;
            movex = INF;
            movey = INF;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j]==9){
                q.push(make_pair(i,j));
                map[i][j]=0;
            }
        }
    }
    shark = 2;
    solve();
    cout << ans << '\n';
    return 0;
}
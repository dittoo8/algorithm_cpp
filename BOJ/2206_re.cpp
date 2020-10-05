#include <iostream>
#include <queue>
#define MAX 1002
using namespace std;
int visit[MAX][MAX][2];
string a[MAX];
const int dx[]= {0,0,-1,1}, dy[] = {-1,1,0,0};
struct pos{
    int x,y,wall; // (x, y) , 벽 지났는지 check
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    fill(&visit[0][0][0],&visit[n][m][1]+1,-1);
    queue<pos> q;
    q.push({0,0,0});
    visit[0][0][0] = 1; // x : 0, y : 0 , 벽 지나지 않음
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int wall = q.front().wall;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx < 0 || nx >=n || ny <0 || ny >=m) continue;
            int nw = a[nx][ny]-'0' + wall;
            if (nw == 2) continue; // 이미 벽을 하나 지난 상태에서, 다음 좌표가 벽일때 continue
            if(visit[nx][ny][nw] == -1 || visit[nx][ny][nw]> visit[x][y][wall]+1 ){
                q.push({nx,ny,nw});
                visit[nx][ny][nw] = visit[x][y][wall]+1;
            }
        }
    }
    int answer = visit[n-1][m-1][0];
    if(answer == -1){
        answer = visit[n-1][m-1][1];
    }else if (visit[n-1][m-1][1] != -1 && visit[n-1][m-1][1] < answer){
        answer = visit[n-1][m-1][1];
    }
    cout << answer << '\n';
    return 0;
}
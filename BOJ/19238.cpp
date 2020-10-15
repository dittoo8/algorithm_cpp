#include <iostream>
#include <vector>
#include <queue>
#define INF 100
using namespace std;
int n,m,hp,sx,sy,finCnt;
int map[21][21];
struct people {
    int sx,sy,ex,ey;
};
vector<people> p;
const int dx[]= {0,0,-1,1}, dy[] = {-1,1,0,0};
int bfs(){
    int visit[21][21];
    fill(&visit[0][0],&visit[20][20]+1,-1);
    queue<pair<int, int> > q;
    q.push(make_pair(sx,sy));
    while(!q.empty()){
        visit[sx][sy] = 0;
        int qS = q.size();
        int nextX = INF, nextY = INF;
        int pId;
        if(map[sx][sy]>0){
            nextX = sx;
            nextY = sy;
            pId = map[sx][sy];
        }else {
            while(qS--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x+dx[i], ny = y+dy[i];
                    if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                    if (map[nx][ny]==-1 || visit[nx][ny]!= -1)continue;
                    q.push(make_pair(nx,ny));
                    visit[nx][ny] = visit[x][y]+1;
                    if (map[nx][ny]>0){
                        if (nextX > nx){
                            nextX = nx;
                            nextY = ny;
                            pId = map[nx][ny];
                        }else if (nextX == nx){
                            if (nextY > ny){
                                nextX = nx;
                                nextY = ny;
                                pId = map[nx][ny];
                            }
                        }
                    }
                }
            }
        }
        if(nextX!=INF){ //현재 거리에서 태울 수 있는 승객이 있을 때
            hp-=visit[nextX][nextY];
            if(hp <0) return -1;
            while(!q.empty()) q.pop();
            q.push(make_pair(nextX,nextY));
            fill(&visit[0][0],&visit[20][20]+1,-1);
            visit[nextX][nextY] = 0;
            map[nextX][nextY] = 0;
            int ex = p[pId].ex, ey = p[pId].ey;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x == ex && y == ey){
                    hp-=visit[x][y];
                    if(hp < 0){
                        return -1;
                    }
                    hp+= visit[x][y]*2;
                    finCnt++;
                    break;
                }
                for(int i=0;i<4;i++){
                    int nx = x+dx[i], ny = y+dy[i];
                    if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                    if (map[nx][ny]==-1 || visit[nx][ny]!= -1) continue;
                    q.push(make_pair(nx,ny));
                    visit[nx][ny] = visit[x][y]+1;
                }
            }
            if(finCnt == m) return hp;
            while(!q.empty()) q.pop();
            q.push(make_pair(ex,ey));
            sx = ex, sy = ey;
            fill(&visit[0][0],&visit[20][20]+1,-1);
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> hp;
    p.resize(m+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
            if(map[i][j]== 1) map[i][j] = -1;
        }
    }
    cin >> sx >> sy ;
    for(int i=1;i<=m;i++){
        cin >> p[i].sx >> p[i].sy >> p[i].ex >> p[i].ey ;
        map[p[i].sx][p[i].sy] = i;
    }
    cout << bfs() << '\n';
    return 0;
}
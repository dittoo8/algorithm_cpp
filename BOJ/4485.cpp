#include <iostream>
#include <queue>
#define MAX 126
#define INF 987654321
using namespace std;
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
struct pos {
    int c, x, y;
    bool operator < (pos a)const { return c > a.c; }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,maps[MAX][MAX],costs[MAX][MAX];
    for(int t=1;;t++){
        cin >> n;
        if (n == 0) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> maps[i][j];
            }
            fill(&costs[0][0], &costs[n][n]+1, INF);
            costs[0][0] = maps[0][0];
            priority_queue<pos> pq;
            pq.push({maps[0][0],0,0});
            while(!pq.empty()){
                int x = pq.top().x, y = pq.top().y;
                int c = pq.top().c;
                pq.pop();
                if(c > costs[x][y]) continue;
                for(int i=0;i<4;i++){
                    int nx = x +dx[i], ny = y+dy[i];
                    if(nx < 0 || nx >= n || ny <0 || ny >=n) continue;
                    if(costs[nx][ny] > c + maps[nx][ny]){
                        costs[nx][ny] = costs[x][y] + maps[nx][ny];
                        pq.push({costs[nx][ny],nx,ny});
                    }
                }
                
            }
        }
        cout << "Problem "<< t <<": "<< costs[n-1][n-1] << '\n';
    }
    return 0;
}
#include <iostream>
#include <queue>
#define MAX 126
#define INF 987654321
using namespace std;
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
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
            queue<pair<int, int> > q;
            q.push(make_pair(0,0));
            while(!q.empty()){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x +dx[i], ny = y+dy[i];
                    if(nx < 0 || nx >= n || ny <0 || ny >=n) continue;
                    if(costs[nx][ny] > costs[x][y] + maps[nx][ny]){
                        costs[nx][ny] = costs[x][y] + maps[nx][ny];
                        q.push(make_pair(nx,ny));
                    }
                }
                
            }
        }
        cout << "Problem "<< t <<": "<< costs[n-1][n-1] << '\n';
    }
    return 0;
}
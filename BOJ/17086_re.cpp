#include <iostream>
#include <queue>
#define MAX 51
using namespace std;
int n,m,answer;
const int dx[] = {-1,-1,-1,0,0,1,1,1}, dy[] = {-1,0,1,-1,1,-1,0,1};
int a[MAX][MAX],safe[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    queue<pair<int, int> > q;
    cin >> n >> m;
    fill(&safe[0][0], &safe[n][m]+1, -1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if (a[i][j]){
                q.push(make_pair(i,j));
                safe[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nx = x+dx[i], ny = y+dy[i];
            if (nx <0 || nx >=n || ny <0 || ny >=m) continue;
            if (safe[nx][ny]== -1 || safe[nx][ny] > safe[x][y]+1){
                safe[nx][ny] = safe[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (safe[i][j] > answer) answer = safe[i][j];
        }
    }
    cout << answer << '\n';
    return 0;
}
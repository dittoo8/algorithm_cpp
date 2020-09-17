#include <iostream>
#define MAX 51
using namespace std;
int n,m,answer;
const int dx[] = {-1,-1,-1,0,0,1,1,1}, dy[] = {-1,0,1,-1,1,-1,0,1};
int a[MAX][MAX],safe[MAX][MAX];
void dfs(int x, int y, int cnt){
    if (safe[x][y] == -1 || safe[x][y] > cnt){
        safe[x][y] = cnt;
    }else return;
    for(int i=0;i<8;i++){
        int nx = x + dx[i], ny = y+dy[i];
        if (nx < 0 || nx >= n || ny <0 || ny >=m) continue;
        dfs(nx,ny,cnt+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    fill(&safe[0][0], &safe[n][m]+1, -1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (a[i][j]){
                dfs(i,j,0);
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
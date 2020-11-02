#include <iostream>
#include <cstring>
#define MAX 301
using namespace std;
int n,m,a[MAX][MAX], b[MAX][MAX];
bool visit[MAX][MAX];
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
void melt(){
    memcpy(b,a,sizeof(a));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]){
                for(int k=0;k<4;k++){
                    int nx = i + dx[k],ny = j+dy[k];
                    if(nx < 0 || nx >= n || ny <0 || ny >= m )continue;
                    if(a[nx][ny]==0 && b[i][j]) {
                        b[i][j]--;
                    }
                }
            }
        }
    }
    memcpy(a,b,sizeof(a));
}
void dfs(int x, int y){
    visit[x][y] = true;
    for(int k=0;k<4;k++){
        int nx = x + dx[k],ny = y+dy[k];
        if(nx < 0 || nx >= n || ny <0 || ny >= m )continue;
        if(visit[nx][ny] || a[nx][ny] == 0) continue;
        dfs(nx,ny);
    }
}
int group_ck(){
    int gr = 0;
    fill(&visit[0][0],&visit[n][m]+1,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] && !visit[i][j]){
                dfs(i,j);
                gr++;
            }
        }
    }
    return gr;
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
    int time = 0;
    int cnt;
    while(true){
        melt();
        cnt = group_ck();
        time++;
        if(cnt >= 2) break;
        if(cnt == 0){
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << time << '\n';
    return 0;
}
#include <iostream>
#define MAX 100
using namespace std;
const int dx[] = {0,0,-1}, dy[] = {-1,1,0};
int  a[MAX][MAX],ans;
void dfs(int x, int y){
    a[x][y]=0;
    if (x==0) {
        if (ans == -1) ans = y;
        return;
    }
    for(int i=0;i<3;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx < 0 || nx>=MAX || ny < 0 || ny >= MAX) continue;
        if (a[nx][ny])  dfs(nx,ny);
    }
}
int main(){
    int t,si,sj;
    for(int tc=1;tc<=10;tc++){
        ans = -1;
        cin >> t;
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                cin >> a[i][j];
                if (a[i][j]==2){
                    si =i, sj=j;
                }
            }
        }
        dfs(si,sj);
        cout << "#" << tc<<' '<< ans << '\n';
    }
    return 0;
}
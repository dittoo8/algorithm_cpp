#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int map[102][102];
bool c[102][102];
int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
void dfs(int h, int x, int y){
    c[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny <0 || ny >= n) continue;
        if(map[nx][ny] > h && !c[nx][ny]) dfs(h,nx,ny);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int maxH = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            maxH = max(maxH, map[i][j]);
        }
    }
    int res = 0;
    for(int i=0;i<=maxH;i++){
        int temp = 0;
        memset(c,0,sizeof(c));
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(map[j][k]> i && !c[j][k]) {
                    temp++;
                    dfs(i,j,k);
                }
            }
        }
        res = max(res,temp);
    }
    cout << res << endl;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int w, h;
int map[52][52];
bool check[52][52];
int dx[] = {-1,-1,-1,0,0,0,1,1,1}, dy[] = {-1,0,1,-1,0,1,-1,0,1};
void dfs(int x, int y){
    check[x][y] = 1;
    for(int i=0;i<9;i++){
        int nx = x+ dx[i], ny = y + dy[i];
        if(nx <0 || nx >= h|| ny <0 ||ny >=w) continue;
        if(map[nx][ny] && !check[nx][ny]) {
            dfs(nx,ny);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                map[i][j]= 0;
                check[i][j] = 0;
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
            }
        }
        int cnt = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!check[i][j] && map[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;

    }
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
const int dx[]={0,0,-1,1}, dy[]={-1,1,0,0};
bool visit[31][31];
char a[31][31];
int n,m;
bool ok (int x,int y){
    return 0<=x && x<n && 0<=y && y < m;
}
int go(int x,int y ,int cnt){
    int ans = 10000000;
    if (cnt == 0) return 0;
    for(int k=0;k<4;k++){
        int nx = x+dx[k],ny= y+dy[k];
        while(ok(nx,ny) && a[nx][ny]=='.'){
            a[nx][ny]='#';
            cnt--;
            nx+=dx[k];
            ny+=dy[k];
        }
        nx-=dx[k];
        ny-=dy[k];
        if (!(x==nx && y == ny)){
            int temp = go(nx,ny,cnt);
            if (temp != -1){
                if (ans > temp+1) ans = temp+1;
            }
        }
        while (!(x == nx && y == ny)) {
            a[nx][ny] = '.';
            cnt++;
            nx -= dx[k];
            ny -= dy[k];
        }
    }
    if (ans == 10000000) return -1;
    else return ans;
}
int main(){
    int tc = 1;
    while (cin >> n >> m ){
        int cnt = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            for(int j=0;j<m;j++){
                if (a[i][j]=='.') cnt++;
            }
        }
        int ans = 10000000;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (a[i][j]=='.'){
                    a[i][j]='#';
                    int temp = go(i,j,cnt-1);
                    if (temp != -1){
                        if (ans > temp) ans = temp;
                    }
                    a[i][j] = '.';
                }
            }
        }
        if (ans == 10000000){
            cout << "Case " << tc <<": " << -1 << '\n';
        } else cout << "Case " << tc <<": " << ans << '\n';
        tc++;
    }
    return 0;
}
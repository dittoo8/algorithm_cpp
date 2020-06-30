#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int dx[]={0,0,-1,1}, dy[]={-1,1,0,0};
char a[1501][1501],b[1501][1501];
bool wck[1501][1501], sck[1501][1501];
int si=-1,sj,ei,ej,r,c;
int main(){
    cin >> r >> c;
    queue<pair<int, int> > water,nwater,swan,nswan;
    for(int i=0;i<r;i++){
        cin >> a[i];
        for(int j=0;j<c;j++){
            if(a[i][j]=='L'){
                if(si == -1){
                    si=i,sj=j;
                }else {
                    ei=i,ej=j;
                }
                a[i][j]='.';
            }
            if (a[i][j]=='.'){
                water.push(make_pair(i,j));
                wck[i][j]=true;
            }
        }
    }
    swan.push(make_pair(si,sj));
    for(int i=0;;i++){
        while(!water.empty()){
            int x = water.front().first,y= water.front().second;
            water.pop();
            a[x][y]='.';
            for(int k=0;k<4;k++){
                int nx = x+ dx[k], ny = y+dy[k];
                if (nx < 0 || nx >= r|| ny < 0 || ny >= c || wck[nx][ny]) continue;
                if (a[nx][ny]=='.') {
                    // 현재 이동할 수 있는 곳
                    water.push(make_pair(nx,ny));
                }else {
                    //다음 턴에 물이되는 곳
                    nwater.push(make_pair(nx,ny));
                }
                wck[nx][ny]=true;
            }
        }
        while(!swan.empty()){
            int x = swan.front().first, y = swan.front().second;
            swan.pop();
            for(int k=0;k<4;k++){
                int nx = x+dx[k],ny = y+dy[k];
                if (nx < 0 || nx >= r || ny <0 || ny >= c || sck[nx][ny]) continue;
                if (a[nx][ny]=='.'){
                    //현재 이동할 수 있는 곳
                    swan.push(make_pair(nx,ny));
                }else {
                    //다음 턴에 물이 되어 이동할 수 있는 곳
                    nswan.push(make_pair(nx,ny));
                }
                sck[nx][ny]=true;
            }
        }
        if  (sck[ei][ej]) {
            cout << i << '\n';
            break;
        }
        water= nwater;
        swan = nswan;
        nwater = queue<pair<int,int>>();
        nswan = queue<pair<int,int>>();
    }
    return 0;
}
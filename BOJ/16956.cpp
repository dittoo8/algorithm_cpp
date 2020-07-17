#include <iostream>
#include <string>
using namespace std;
int r,c;
const int dx[] ={-1,1,0,0}, dy[]={0,0,-1,1};
string a[501];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    for(int i=0;i<r;i++){
        cin >> a[i];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]=='S'){
                for(int k=0;k<4;k++){
                    int nx = i+dx[k], ny = j+dy[k];
                    if(nx <0 || nx >= r || ny<0 || ny >=c) continue;
                    if(a[nx][ny]=='S') continue;
                    if(a[nx][ny]=='W') {
                        cout << 0 <<'\n';
                        return 0;
                    }else a[nx][ny]='D';
                }
            }
        }
    }
    cout << 1 << '\n';
    for(int i=0;i<r;i++){
        cout << a[i] << '\n';
    }
    return 0;
}
#include <iostream>
using namespace std;
int a[101][101],n,m,ans;
const int dx[] = {0,0,-1,1}, dy[]={-1,1,0,0};
int main(){
    cin >> n >> m;
    ans=n*m*2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<4;k++){
                int nx = i+dx[k], ny = j+dy[k];
                int gap = a[i][j] - a[nx][ny];
                if (gap > 0) ans+=gap;
            }
        }
    }
    cout << ans  << '\n';
    return 0;
}
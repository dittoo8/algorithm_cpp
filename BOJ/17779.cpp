#include <iostream>
using namespace std;
int n,ans = 4000000;
int region[6]; //구역 인구수
int d[21][21],a[21][21];
void check(int x, int y, int d1, int d2){
    fill(&d[0][0],&d[20][20]+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<x+d1 && j<=y){
                d[i][j]=1;
            }else if (i<=x+d2 && y <j){
                d[i][j] =2;
            }else if(i >=x+d1 && j< y-d1+d2){
                d[i][j]=3;
            }else if(i > x+d2 && j >=y-d1+d2){
                d[i][j]=4;
            }
        }
    }
    fill(&region[0], &region[5]+1,0);
    for(int i=0;i<=d1;i++){
        d[x+i][y-i]=5;
        d[x+d2+i][y+d2-i]=5;
    }
    for(int i=0;i<=d2;i++){
        d[x+i][y+i]=5;
        d[x+d1+i][y-d1+i]=5;
    }
    for(int i=x+1;i<x+d1+d2;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]==5){
                while(d[i][j+1]!=5){
                    j++;
                    d[i][j]=5;
                }
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            region[d[i][j]]+=a[i][j];
        }
    }
    int min = 400000;
    int max = 0;
    for(int i=1;i<=5;i++){
        if(region[i]> max) max = region[i];
        if(region[i]<min) min = region[i];
    }
    if (ans > max-min) ans = max-min;
}
void solve(int x, int y){
    for(int d1 = 1;d1<=n;d1++){
        for(int d2=1;d2<=n;d2++){
            if(x+d1+d2 > n || y-d1 < 1 || y+d2 > n)continue;
            check(x,y,d1,d2);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            solve(i,j);
        }
    }
    cout << ans << '\n';
    return 0;
}
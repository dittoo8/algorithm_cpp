#include <iostream>
#include <string>
using namespace std;
int r,c,n;
const int dx[]={0,0,-1,1}, dy[]={-1,1,0,0};
int timer[201][201];
string map[201];
void solve(int N){
    for(int t=2;t<=N;t++){
        if(t%2 == 0){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(map[i][j] == 'O') continue;
                    map[i][j] = 'O';
                    timer[i][j]=t+3;
                }
            }
        }else {
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if (timer[i][j]==t){
                        for(int k=0;k<4;k++){
                            int nx = i+ dx[k], ny = j + dy[k];
                            if (nx < 0 || nx >= r || ny <0 || ny >=c) continue;
                            map[nx][ny]='.';
                        }
                        map[i][j]='.';
                        timer[i][j] = 0;
                    }
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c >> n;
    for(int i=0;i<r;i++){
        cin >> map[i];
        for(int j=0;j<c;j++){
            if (map[i][j]=='O'){
                timer[i][j]=3;
            }
        }
    }
    if (n==1){
         for(int i=0;i<r;i++){
            cout << map[i] << '\n';
        }
        return 0;
    }else if (n%4 == 2) n=2;
    else if (n%4 == 3) n=3;
    else if (n%4 == 0) n=4;
    else if (n%4 == 1) n=5;
    solve(n);
    
    for(int i=0;i<r;i++){
        cout << map[i] << '\n';
    }
    return 0;
}
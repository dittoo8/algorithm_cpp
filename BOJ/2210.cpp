#include <cstdio>
#include <vector>
#include <string>
#include <set>
using namespace std;
int board[5][5];
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
set<int> ret;
void solve(int x, int y, int ans, int len){
    if(len == 6){
        ret.insert(ans);
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx >=5 || nx <0 || ny >=5 || ny <0) continue;
        solve(nx,ny, ans*10+board[nx][ny],len+1);
    }
}
int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&board[i][j]);
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            solve(i,j,board[i][j],1);
        }
    }
    printf("%d\n",(int)ret.size());
    return 0;
}
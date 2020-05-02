#include <cstdio>
using namespace std;
const int dx[]={-1,0,0,1}, dy[]={0,1,-1,0};
int r,c,ocnt,vcnt,ores,vres;
char a[251][251];
bool ck[251][251];
void dfs(int x, int y){
    ck[x][y]=true;
    if (a[x][y]=='o') ocnt++;
    else if (a[x][y]=='v') vcnt++;
    for(int i=0;i<4;i++){
        int nx = x +dx[i],ny= y+dy[i];
        if (nx < 0 || nx >= r || ny <0 || ny >=c) continue;
        if (!ck[nx][ny] && a[nx][ny]!='#') dfs(nx,ny);
    }
}
int main(){
    scanf("%d %d", &r, &c);
    for(int i=0;i<r;i++){
        scanf("%s",a[i]);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if (!ck[i][j] && a[i][j]!='#'){
                dfs(i,j);
                if (ocnt > vcnt) ores+=ocnt;
                else vres+=vcnt;
                ocnt=0;
                vcnt=0;
            }
        }
    }
    printf("%d %d\n",ores,vres);
    return 0;
}
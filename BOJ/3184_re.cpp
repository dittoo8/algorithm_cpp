#include <cstdio>
#include <queue>
using namespace std;
char a[251][251];
bool visit[251][251];
int r,c,ocnt,vcnt;
const int dx[] = {0,-1,0,1}, dy[]={-1,0,1,0};
void bfs(int i,int j){
    visit[i][j]=true;
    queue<pair<int, int> > q;
    q.push(make_pair(i,j));
    int otmp=0,vtmp=0;
    while(!q.empty()){
        int x = q.front().first;
        int y= q.front().second;
        q.pop();
        if(a[x][y]=='o') otmp++;
        else if (a[x][y]=='v') vtmp++;
        for(int k=0;k<4;k++){
            int nx = x+dx[k],ny = y+dy[k];
            if(visit[nx][ny] ||a[nx][ny]=='#') continue;
            if (nx <0 || nx >=r || ny <0 || ny >=c) continue;
            visit[nx][ny]=true;
            q.push(make_pair(nx,ny));
        }
    }
    if(otmp>vtmp) ocnt+=otmp;
    else vcnt+=vtmp;
}
int main(){
    scanf("%d %d", &r, &c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%1s",&a[i][j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]!='#'&& !visit[i][j]){
                bfs(i,j);
            }
        }
    }
    printf("%d %d\n",ocnt,vcnt);
    return 0;
}
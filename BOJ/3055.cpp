#include <cstdio>
#include <queue>
using namespace std;
int r,c;
char map[52][52];
int check[52][52];
int dx[] = {0,-1,1,0}, dy[] = {1,0,0,-1};
int sx, sy, ex, ey;
queue<pair<int, int> > w;
void bfs(){
    queue<pair<int, int> > q;
    q.push(make_pair(sx,sy));
    check[sx][sy] = 0;
    while(!q.empty()){
        int wSize = w.size();
        while(wSize--){
            int wx = w.front().first;
            int wy = w.front().second;
            w.pop();
            for(int i=0;i<4;i++){
                int wnx = wx + dx[i], wny = wy +dy[i];
                if(map[wnx][wny]=='.') {
                    map[wnx][wny] = '*';
                    w.push(make_pair(wnx, wny));
                }
            }
        }
        int qSize = q.size();
        while(qSize--){

            int nowx = q.front().first;
            int nowy = q.front().second;
            q.pop();
            if(nowx == ex && nowy == ey){
                printf("%d\n", check[nowx][nowy]);
                return;
            }
            for(int i=0;i<4;i++){
                int nx = nowx + dx[i], ny = nowy + dy[i];
                if(nx <0 || nx >= r || ny <0 || ny >= c) continue;
                if(check[nx][ny]==0 && (map[nx][ny]=='.' || map[nx][ny] == 'D')){
                    //조건 잘보고 계산
                    check[nx][ny] = check[nowx][nowy] + 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }

    }
    printf("KAKTUS\n");
}
int main(){
    
    scanf("%d %d", &r, &c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%1s", &map[i][j]);
            if(map[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            else if(map[i][j] == 'D') {
                ex = i;
                ey = j;
            }
            else if(map[i][j]== '*') {
                w.push(make_pair(i,j));
            }
        }
    }

    bfs();

    return 0;
}
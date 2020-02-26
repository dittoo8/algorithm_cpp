#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int w,h;
char a[101][101];
int dist[101][101];
vector<pair<int, int> > v;
int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
void bfs(){
    queue<pair<int, int> > q;
    int si=v[0].first,sj=v[0].second;
    int ei=v[1].first,ej=v[1].second;
    q.push(make_pair(si, sj));
    while(!q.empty()){
        int x = q.front().first, y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i],ny = y+dy[i];
            while(0<=nx && nx <h && 0 <=ny && ny < w && a[nx][ny]!='*'){
                if(!dist[nx][ny]){
                    dist[nx][ny] =dist[x][y]+1;
                    q.push(make_pair(nx, ny));
                }
                nx+=dx[i],ny+=dy[i];
            }
        }
    }
}
int main(){
    scanf("%d %d",&w,&h);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf(" %1c", &a[i][j]);
            if(a[i][j]=='C'){
                v.push_back(make_pair(i,j));
            }
        }
    }
    bfs();
    printf("%d\n",dist[v[1].first][v[1].second]-1);
    return 0;
}
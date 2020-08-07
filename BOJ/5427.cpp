#include <iostream>
#include <queue>
using namespace std;
char b[1002][1002];
queue<pair<int, int> > fire;
queue<pair<int, int> > pos;
int n, h, w, si, sj, ex, ey;
int visit[1002][1002];
const int dx[]= {0,0,-1,1}, dy[] = {-1,1,0,0};
void bfs(){
    pos.push(make_pair(si,sj));
    visit[si][sj] =  1;
    while(!pos.empty()){
        int fSize = (int)fire.size();
        while(fSize--){
            int fx = fire.front().first, fy = fire.front().second;
            fire.pop();
            for(int k=0;k<4;k++){
                int fnx = fx + dx[k], fny = fy + dy[k];
                if (fnx < 0 || fnx >= h || fny <0 || fny >= w) continue;
                if  (b[fnx][fny]=='.'){
                    b[fnx][fny] = '*';
                    fire.push(make_pair(fnx,fny));
                }
            }
        }
        int posSize = (int)pos.size();
        while(posSize--){
            int x = pos.front().first, y = pos.front().second;
            pos.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx <0 || nx >= h ||ny <0 || ny >= w) {
                    cout  << visit[x][y] << '\n';
                    return;
                }
                if(b[nx][ny]=='#' || b[nx][ny]=='*'|| visit[nx][ny]) continue;
                pos.push(make_pair(nx,ny));
                visit[nx][ny] = visit[x][y] + 1;
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while(n--){
        while(!fire.empty()) fire.pop();
        while(!pos.empty()) pos.pop();
        cin >> w >> h;
        for(int i=0;i<h;i++){
            cin >> b[i];
            for(int j=0;j<w;j++){
                if(b[i][j] == '@') {
                    si = i, sj = j;
                    b[i][j]='.';
                }else if (b[i][j] == '*'){
                    fire.push(make_pair(i,j));
                } else visit[i][j]=0;
            }
        }
        bfs();
    }
    return 0;
}
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 51
using namespace std;
int n,m,ans;
const int dx[] = {0,0,-1,1},dy[]={-1,1,0,0};
string map[MAX];
bool visit[MAX][MAX];
void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    int d = 0;
    fill(&visit[0][0],&visit[n][m]+1,0);
    visit[x][y] = true;
    while(!q.empty()){
        int qS = q.size();
        ans = max(ans,d);
        while(qS--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x+dx[i], ny = y+dy[i];
                if (nx < 0 || nx >= n || ny <0 || ny>=m)continue;
                if(map[nx][ny]=='W' || visit[nx][ny]) continue;
                q.push(make_pair(nx,ny));
                visit[nx][ny] = true;
            }
        }
        d++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> map[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == 'L'){
                bfs(i,j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
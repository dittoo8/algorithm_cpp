#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
vector<int> res;
int n, cnt;
int map[26][26];
void dfs(int x, int y) {
    map[x][y] = 0;
    cnt++;
    for(int i=0;i<4;i++){
        int nx = x+ dx[i], ny = y + dy[i];
        if (nx <0 || nx >= n || ny <0 || ny >= n) continue;
        if(map[nx][ny]==1) {
            map[nx][ny] = 0;
            dfs(nx,ny);
        }
    }
}
void bfs(int i, int j){
    queue<pair<int, int> > q;
    q.push(make_pair(i,j));
    map[i][j] = 0;
    cnt++;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx <0 || nx >=n || ny <0 || ny >= n) continue;
            if(map[nx][ny] == 1) {
                map[nx][ny] = 0;
                cnt++;
                q.push(make_pair(nx,ny));
            }
            
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == 1){
                cnt = 0;
                // dfs(i,j);
                bfs(i,j);
                res.push_back(cnt);
            }
        }
    }
    printf("%d\n", (int)res.size());
    sort(res.begin(), res.end());
    for(int i=0;i<res.size();i++){
        printf("%d\n",res[i]);
    }
    return 0;
}

#include <iostream>
#include <queue>
#define MAX 21
using namespace std;
int n,m;
int a[MAX][MAX];
bool ck[MAX][MAX];
const int dx[] = {0,0,-1,1}, dy[]= {-1,1,0,0};
int bfs(){
    fill(&ck[0][0],&ck[n][m]+1,0);
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==2 && !ck[i][j]){
                bool dead = true;
                queue<pair<int, int> > q;
                q.push(make_pair(i,j));
                ck[i][j]= true;
                int cur = 0;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    cur++;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = x+dx[k], ny = y+dy[k];
                        if(nx < 0 || nx >=n || ny < 0 || ny >=m) continue;
                        if(a[nx][ny]==0) dead = false;
                        else if (a[nx][ny]==2 && !ck[nx][ny]){
                            q.push(make_pair(nx,ny));
                            ck[nx][ny] = true;
                        }
                    }
                }
                if(dead){
                cnt+=cur;
                }
            }
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int x1 =0;x1<n;x1++){
        for(int y1=0;y1<m;y1++){
            if(a[x1][y1]!=0) continue;
            for(int x2=0;x2<n;x2++){
                for(int y2=0;y2<m;y2++){
                    if(x1 == x2 && y1 == y2) continue;
                    if (a[x2][y2]!=0) continue;
                    a[x1][y1] = 1;
                    a[x2][y2] = 1;
                    int cur = bfs();
                    if (ans < cur){
                        ans =cur;
                    }
                    a[x1][y1] = 0;
                    a[x2][y2] = 0;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
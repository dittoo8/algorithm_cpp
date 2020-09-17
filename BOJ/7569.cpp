#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
const int dx[]={0,0,-1,1,0,0};
const int dy[]={-1,1,0,0,0,0};
const int dz[]={0,0,0,0,1,-1};
int a[MAX][MAX][MAX];
struct pos {
    int z,x,y;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m,l,allCnt;
    queue<pos> q;
    cin >> n >> m >> l;
    allCnt = n*m*l;
    for(int k=0;k<l;k++){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> a[k][i][j];
                if (a[k][i][j]==1){
                    q.push({k,i,j});
                }else if (a[k][i][j]==-1){
                    allCnt--;
                }
            }
        }
    }
    int day = 0;
    while(!q.empty()){
        int qS = q.size();
        bool check = false;
        while(qS--){
            int x = q.front().x;
            int y = q.front().y;
            int z = q.front().z;
            q.pop();
            allCnt--;
            for(int i=0;i<6;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                int nz = z+dz[i];
                if (nx < 0 || nx >=m || ny <0 || ny >= n || nz < 0 || nz>=l) continue;
                if(a[nz][nx][ny]==0){
                    a[nz][nx][ny] = 1;
                    q.push({nz,nx,ny});
                    check = true;
                }
            }
        }
        if (!check) break;
        day++;
    }
    if(allCnt <=0){
        cout << day << '\n';
    }else cout << -1 << '\n';
    return 0;
}
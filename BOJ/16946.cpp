#include <iostream>
#include <cstring>
using namespace std;
int n,m,id,cnt;
char a[1001][1001];
char res[1001][1001];
int idx[1001][1001];
int idxcnt[1000001];
const int dx[]={0,0,-1,1}, dy[]={-1,1,0,0};
bool ck[1001][1001],idxck[1000001];
void dfs(int x,int y){
    idx[x][y]= id;
    cnt++;
    for(int k=0;k<4;k++){
        int nx = x+dx[k],ny= y+dy[k];
        if (nx <0 || nx >= n || ny <0 || ny>=m) continue;
        if(idx[nx][ny] || a[nx][ny]=='1') continue;
        dfs(nx,ny);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='0' && idx[i][j]==0){
                id++;
                cnt=0;
                dfs(i,j);
                idxcnt[id] = cnt;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (a[i][j]=='0'){
                res[i][j]='0';
            }else {
                int tmp = 0;
                memset(idxck,0,id+1);
                for(int k=0;k<4;k++){
                    int nx = i+dx[k], ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m )continue;
                    if (idxck[idx[nx][ny]]) continue;
                    idxck[idx[nx][ny]]=true;
                    tmp+=idxcnt[idx[nx][ny]];
                }
                tmp++;
                tmp%=10;
                res[i][j]=tmp+'0';
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << res[i] << '\n';
    }
    return 0;
}
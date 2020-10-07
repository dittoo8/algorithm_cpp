#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int> > v;
int n,m,answer = -1;
int a[101][101];
int ck[101][101];
bool vi_ck[11];
const int dx[]= {0,0,-1,1}, dy[]={-1,1,0,0};
void solve(){
    fill(&ck[0][0],&ck[100][100]+1,-1);
    queue<pair<int, int> > q;
    for(int i=0;i<v.size();i++){
        if(vi_ck[i]){
            q.push(make_pair(v[i].first,v[i].second));
            ck[v[i].first][v[i].second] = 0;
        }
    }
    while(!q.empty()){
        int x= q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx >=n || ny <0 || ny >=n) continue;
            if(a[nx][ny] != 1 && ck[nx][ny] == -1 ){
                ck[nx][ny] = ck[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    int cur = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0){
                if(ck[i][j]==-1) return;
                if (cur < ck[i][j]) cur = ck[i][j];
            }
        }
    }
    if(answer == -1 || answer > cur){
        answer = cur;
    }
}
void check_virus(int idx, int cnt){
    if(idx == (int)v.size()){
        if (cnt == m){
            solve();
        }
        return;
    }
    vi_ck[idx]=true;
    check_virus(idx+1,cnt+1);
    vi_ck[idx]=false;
    check_virus(idx+1,cnt);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            if (a[i][j]==2){
                v.push_back(make_pair(i,j));
            }
        }
    }
    check_virus(0,0);
    cout << answer << '\n';
    return 0;
}
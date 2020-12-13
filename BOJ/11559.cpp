#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str[12];
vector<pair<int, int> > v;
const int dx[] = { 0,0,-1,1}, dy[] = {-1,1,0,0};
bool visit[12][6];
void dfs(int x, int y){
    visit[x][y]= true;
    v.push_back(make_pair(x,y));
    for(int k=0;k<4;k++){
        int nx = x+dx[k], ny = y+dy[k];
        if(nx < 0 || nx >= 12 || ny < 0 || ny>=6) continue;
        if(visit[nx][ny]) continue;
        if(str[x][y] == str[nx][ny]){
            dfs(nx,ny);
        }
    }
}
void fall_blocks(){
    for (int j=0; j<6; j++) {
        for (int i=11; i>=0; i--) {
            if (str[i][j] == '.') continue;
            for (int k=11; k>=i; k--) {
                if (str[k][j] == '.') {
                    str[k][j] = str[i][j];
                    str[i][j] = '.';
                }
            }
        }
    }
}
bool find_group(){
    bool find = false;
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            if (str[i][j]=='.' || visit[i][j]) continue;
            dfs(i,j);
            if((int)v.size()>= 4){
                find = true;
                for(int t=0;t<v.size();t++){
                    str[v[t].first][v[t].second] = '.';
                }
            }
            v.clear();
        }
    }
    return find;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i=0;i<12;i++){
        cin>> str[i];
    }
    int ans = 0;
    bool ck = false;
    while(true){
        fill(&visit[0][0], &visit[11][5]+1,0);
        ck = find_group();
        if(ck == false) break;
        ans++;
        fall_blocks();
    }
    cout << ans << '\n';
    return 0;
}
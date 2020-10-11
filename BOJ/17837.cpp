#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n,k;
struct pos{
    int x,y,d;
};
vector<pos> v;
const int dx[]={0,0,-1,1}, dy[]={1,-1,0,0};
int a[13][13];
string mp[13][13] = {""};
bool move(int x, int y, int d, char target){
    string now = mp[x][y].substr(mp[x][y].find(target));
    int nx = x+dx[d],ny = y+dy[d];
    if(nx<1 || nx>n || ny<1  || ny>n || a[nx][ny]==2) {
        //체스판을 벗어나거나, 다음칸이 파란색일경우 방향을 바꿈
        if(d == 1 || d ==3){
            d--;
        }else if(d==0 || d == 2){
            d++;
        }
        v[target-'0'].d = d;
        if(x+dx[d]<1 || x+dx[d]>n || y+dy[d]<1  || y+dy[d]>n || a[x+dx[d]][y+dy[d]]==2){
            //그 다음칸도 파란색이거나 범위를 벗어나면 움직이지 않음
            return false;
        }
    }
    nx = x+dx[d],ny = y+dy[d];
    if (a[nx][ny]==1){ //다음칸이 빨간색이면 순서바꿈
        reverse(now.begin(),now.end());
    }
    for(int i=0;i<now.length();i++){
        v[now[i]-'0'].x =nx;
        v[now[i]-'0'].y =ny;
    }
    mp[x][y].erase(mp[x][y].find(target));
    mp[nx][ny]+=now;
    if(mp[nx][ny].length()>=4) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    v.resize(k);
    for(int i=0;i<k;i++){
        cin >> v[i].x >> v[i].y >> v[i].d;
        v[i].d--;
        mp[v[i].x][v[i].y]+=to_string(i);
    }
    for(int time = 1;time<=1000;time++){
        for(int i=0;i<k;i++){
            if(move(v[i].x,v[i].y, v[i].d, i+'0')){
                cout << time << '\n';
                return 0;
            }
        }
        
    }
    cout << -1 << '\n';
    return 0;
}
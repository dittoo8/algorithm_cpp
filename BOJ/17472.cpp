#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int dx[]={0,0,-1,1}, dy[] = {-1,1,0,0};
int n,m,idx;
int map[11][11];
struct adj{
    int c,a,b;
};
int pa[7] = {0,1,2,3,4,5,6};
bool visit[11][11];
vector<adj> v;
bool cmp(adj a, adj b){
    return a.c < b.c;
}
int getP(int x){
    if (pa[x] == x) return x;
    else {
        int y = getP(pa[x]);
        pa[x] = y;
        return y;
    }
}
void unionP(int a, int b){
    a = getP(a);
    b = getP(b);
    if (a < b){
        pa[b] =a;
    }else pa[a] = b;
}
void dfs(int x, int y, int id){
    map[x][y] = id;
    visit[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y +dy[i];
        if (nx < 0 || nx >= n || ny <0 || ny>=m) continue;
        if (map[nx][ny] && !visit[nx][ny]){
            dfs(nx,ny,id);
        }
    }
}
bool in_range(int x, int y){
    return x >=0 && x < n && y >=0 && y < m;
}
void find_adj(int x, int y , int id){
    for(int i=0;i<4;i++){
        int nx = x+dx[i],ny = y+dy[i];
        int dist = 0;
        while(in_range(nx,ny) && map[nx][ny]!=id){
            if(map[nx][ny]){
                if(dist>=2){
                    v.push_back({dist,id,map[nx][ny]});
                }
                break;
            }
            dist++;
            nx+=dx[i];
            ny+=dy[i];
        }
    }

}
void make_adj(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]){
                find_adj(i,j,map[i][j]);
            }
        }
    }
}
void make_range(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] && !visit[i][j]){
                idx++;
                dfs(i,j,idx);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    make_range();
    make_adj();
    int cnt=0,answer = 0;
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        int a= getP(v[i].a);
        int b= getP(v[i].b);
        if (a == b) continue;
        cnt++;
        unionP(a,b);
        answer+=v[i].c;
        if (cnt +1 == idx) {
            cout << answer << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
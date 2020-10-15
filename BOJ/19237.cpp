#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct shark {
    int x, y,d;
    int sdx[4][4];
    int sdy[4][4];
};
int n,m,k,deadCnt;
int map[21][21],mapTime[21][21],mapSmell[21][21];
bool dead[401];
const int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
vector<shark> S;
void removeSmell(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mapTime[i][j]){
                mapTime[i][j]--;
                if(mapTime[i][j]==0){
                    mapSmell[i][j] =0;
                }
            }
        }
    }
}
void move(int now){
    int nowX = S[now].x, nowY = S[now].y;
    int nowD = S[now].d;
    map[nowX][nowY] = 0;
    //비어있는 곳 찾기
    for(int i=0;i<4;i++){
        int nx = nowX + dx[S[now].sdx[nowD][i]],ny = nowY + dy[S[now].sdy[nowD][i]];
        if (nx < 0 || nx >= n || ny <0 ||  ny >= n) continue;
        if (mapTime[nx][ny]==0){
            S[now].x = nx;
            S[now].y = ny;
            S[now].d = S[now].sdx[nowD][i];
            return;
        }
    }
    //자신의 냄새가 있는 곳 찾기
    for(int i=0;i<4;i++){
        int nx = nowX + dx[S[now].sdx[nowD][i]],ny = nowY + dy[S[now].sdy[nowD][i]];
        if (nx < 0 || nx >= n || ny <0 ||  ny >= n) continue;
        if(mapSmell[nx][ny]==now){
            S[now].x = nx;
            S[now].y = ny;
            S[now].d = S[now].sdx[nowD][i];
            return;
        }
    }
    dead[now] = true;
    deadCnt++;
}
void newPosition(){
    for(int i=1;i<=m;i++){
        if (dead[i]) continue;
        if(map[S[i].x][S[i].y]){
            dead[i] = true;
            deadCnt++;
        }else {
            map[S[i].x][S[i].y] = i;
            mapSmell[S[i].x][S[i].y] = i;
            mapTime[S[i].x][S[i].y] = k;
        }
    }
}
int solve(){
    for(int t=1;t<=1000;t++){
        for(int i=1;i<=m;i++){
            if(dead[i]) continue;
            move(i);
        }
        removeSmell();
        newPosition();
        if(deadCnt+1 == m) return t;
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    S.resize(m+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j]){
                S[map[i][j]].x = i;
                S[map[i][j]].y = j;
                mapTime[i][j] = k;
                mapSmell[i][j] = map[i][j];
            }
        }
    }
    for(int i=1;i<=m;i++){
        cin >> S[i].d ;
        S[i].d--;
    }
    int dir;
    for(int k=1;k<=m;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cin >> dir;
                dir--;
                S[k].sdx[i][j] = dir;
                S[k].sdy[i][j] = dir;
            }
        }
    }
    cout << solve() << '\n';
    return 0;
}
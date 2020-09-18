#include <iostream>
#include <queue>
#define MAX 17
using namespace std;
int n;
int a[MAX][MAX];
int cnts[MAX][MAX];
const int dx[]={0,1,1}, dy[]={1,0,1};
struct pipe {
    int x,y,d;
};
bool ck_hol(int x, int y){
    return y+1 < n && !a[x][y+1];
}
bool ck_ver(int x, int y){
    return x+1 < n && !a[x+1][y];
}
bool ck_di(int x, int y){
    bool ck = true;
    for(int i=0;i<3;i++){
        if(x+dx[i] <0 || x+dx[i]>=n || y+dy[i]<0 || y+dy[i]>=n){
            ck = false;
            break;
        }
        if(a[x+dx[i]][y+dy[i]]) {
            ck = false;
            break;
        }
    }
    return ck;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    queue<pipe> q;
    q.push({0,1,0});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();
        if(d==0){ //가로
            if(ck_hol(x,y)){
                cnts[x][y+1]++;
                q.push({x,y+1,0});
            }
            if(ck_di(x,y)){
                cnts[x+1][y+1]++;
                q.push({x+1,y+1,2});
            }
        }else if (d ==1){ //세로
            if(ck_ver(x,y)){
                cnts[x+1][y]++;
                q.push({x+1,y,1});
            }
            if(ck_di(x,y)){
                cnts[x+1][y+1]++;
                q.push({x+1,y+1,2});
            }
        }else { // 대각선
            if(ck_hol(x,y)){
                cnts[x][y+1]++;
                q.push({x,y+1,0});
                }
            if(ck_ver(x,y)){
                cnts[x+1][y]++;
                q.push({x+1,y,1});
            }
            if(ck_di(x,y)){
                cnts[x+1][y+1]++;
                q.push({x+1,y+1,2});
            }
        }
    }
    cout << cnts[n-1][n-1] << '\n';
    return 0;
}
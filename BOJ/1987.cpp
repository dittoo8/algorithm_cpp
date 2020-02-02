#include <iostream>
#include <cstdio>
using namespace std;
int r,c;
char map[22][22];
int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
bool check[27];
int backtrack(int x,int y, int cnt){
    int temp = 0;
    check[map[x][y]-'A'] = true;

    for(int i=0;i<4;i++){
        int nx = x+ dx[i], ny = y + dy[i];
        if (nx <0 || nx >= r || ny <0 || ny >= c) continue;
        if(check[map[nx][ny]-'A']==0){
            //이 알파벳을 아직 안지났을때,
            temp = max(temp, backtrack(nx,ny,cnt++));
            //이번칸 (x,y)를 지나고 DFS를 계속 수행하였을때의 최대값 구함
        }
    }
    check[map[x][y]-'A'] = false;
    //이번칸을 안지났을때 (이번 알파벳을 안지났다고 되돌림)로 바꿈
    return temp+1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> map[i][j];
        }
    }
    cout << backtrack(0,0,0) << endl;
    return 0;
}
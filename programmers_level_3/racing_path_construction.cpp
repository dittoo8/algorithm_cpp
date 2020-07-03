#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int dx[] = {0,0,-1,1}, dy[]={-1,1,0,0};
struct path {
    int x,y,z;
};
int solution(vector<vector<int>> board) {
    int answer = -1;
    int bSize = (int)board.size();
    int dist[26][26][4];
    memset(dist,-1,sizeof(dist));
    queue<path> q;
    q.push({0,0,1});
    q.push({0,0,3});
    dist[0][0][1]=0;
    dist[0][0][3]=0;
    while(!q.empty()){
        int x = q.front().x, y = q.front().y;
        int z = q.front().z; q.pop();
        int lastcost = dist[x][y][z];
        for(int k=0;k<4;k++){
            int nx = x+dx[k], ny= y+dy[k];
            if (nx <0 || nx >= bSize || ny <0 || ny>=bSize || board[nx][ny]) continue;
            if (k==z){
                if (dist[nx][ny][k]==-1 || dist[nx][ny][k]> lastcost+100){
                    dist[nx][ny][k]=lastcost+100;
                    q.push({nx,ny,k});
                }
            }else if (dist[nx][ny][k]==-1 || dist[nx][ny][k]> lastcost+600){
                    dist[nx][ny][k]= lastcost+600;
                    q.push({nx,ny,k});
                }
        }
    }
    for(int i=0;i<4;i++){
        if (dist[bSize-1][bSize-1][i] == -1) continue;
        if (answer == -1 || answer > dist[bSize-1][bSize-1][i]){
            answer = dist[bSize-1][bSize-1][i];
        }
    }
    return answer;
}
int main(){
    vector<vector<int> > v = {{0,0,0},{0,0,0},{0,0,0}};
    cout << solution(v) << endl;
    return 0;
}
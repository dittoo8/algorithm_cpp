#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int dx[] = {0,0,-1,1}, dy[]={-1,1,0,0};
int dist[101][101];
int solution(vector<vector<int> > maps){
    int answer = 0;
    dist[0][0]= 1;
    int n = maps.size()-1;
    int m = maps[0].size()-1;
    queue<pair<int, int> > q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n && y ==m){
            return dist[x][y];
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];
            if (nx <0 || nx >n || ny <0 || ny > m) continue;
            if (maps[nx][ny]==0 || dist[nx][ny]!=0) continue;
            dist[nx][ny]= dist[x][y]+1;
            q.push(make_pair(nx,ny));
        }
    }
    
    return -1;
}
int main(){
    vector<vector<int> > v = {
        {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}
    };
    cout << solution(v) <<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 26
using namespace std;
const int dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0}; 
int n,cnt;
string a[MAX];
void dfs(int x, int y){
    cnt++;
    a[x][y] = '0';
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx < 0 || nx >= n || ny <0 || ny >= n) continue;
        if(a[nx][ny]=='1'){
            dfs(nx,ny);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> answer;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (a[i][j]=='1'){
                cnt = 0;
                dfs(i,j);
                answer.push_back(cnt);
            }
        }
    }
    sort(answer.begin(),answer.end());
    cout << answer.size() << '\n';
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }
    return 0;
}
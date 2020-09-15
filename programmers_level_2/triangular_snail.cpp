#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int dx[] = {1,0,-1}, dy[] = {0,1,-1};
vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int> > v(n,vector<int>(n));
    int num = 1;
    int cnt = 0;
    int len = n;
    int idx = 0;
    int x = 0, y=0;
    while(num<=n*(n+1)/2){
        v[x][y] = num;
        cnt++;
        if(cnt == len){
            len--;
            cnt = 0;
            idx++;
        }
        x+=dx[idx%3];
        y+=dy[idx%3];
        num++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (v[i][j]==0) continue;
            answer.push_back(v[i][j]);
        }
    }
    return answer;
}
int main(){
    vector<int> res;
    res =  solution(6);
    for(int i=0;i<res.size();i++){
        cout << res[i] << ' ';
    }
    return 0;
}
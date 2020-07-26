#include  <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int d[101][100001];
int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    d[0][travel[0][0]] = travel[0][1];
    d[0][travel[0][2]] = travel[0][3];
    for(int i=1;i<travel.size();i++){
        for(int j=0;j<=K;j++){
            if(d[i-1][j]==0) continue;
            if (j+travel[i][0] <= K){
                d[i][j+travel[i][0]]= d[i-1][j]+travel[i][1];
                answer  = max(answer,d[i][j+travel[i][0]]);
            }
            if( j+travel[i][2]<=K){
                d[i][j+travel[i][2]] = max(d[i][j+travel[i][2]], d[i-1][j] + travel[i][3]);
                answer = max(answer, d[i][j+travel[i][2]]);
            }
        }
    }
    return answer;
}
int main(){
    vector<vector<int> > v = {{500, 200, 200, 100}, {800, 370, 300, 120}, {700, 250, 300, 90}};
    cout << solution(1650,v) <<endl;
    return 0;
}
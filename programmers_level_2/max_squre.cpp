#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    if(board[0][0]) answer=1;
    for(int i=1;i<board.size();i++){
        for(int j=1;j<board[0].size();j++){
            if(board[i][j]==1){
                board[i][j] = min(min(board[i-1][j-1],board[i-1][j]),board[i][j-1])+1;
                
            }
            if(board[i][j]>answer) answer = board[i][j];
        }
    }

    return answer*answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(1);
    vector<int> v3;
    v3.push_back(1);
    v3.push_back(1);
    v3.push_back(1);
    v3.push_back(1);
    vector<int> v4;
    v4.push_back(0);
    v4.push_back(0);
    v4.push_back(1);
    v4.push_back(0);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    cout << solution(v) << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
// #include <map>
#include <iostream>
#include <algorithm>
using namespace std;
 
int block[110][110][2];
int N;
 
bool insert(int x, int y, int type){
    if(type == 0){ // 기둥
        // 기둥은 바닥 위에 있거나
        if(y == 0) return true;
        // 보의 한쪽 끝 부분 위에 있거나 
        else if((x-1 >= 0 && block[x-1][y][1] == 1) || block[x][y][1] == 1)return true;
        // 또는 다른 기둥 위에 있어야 합니다.
        else if(y-1 >= 0 && block[x][y-1][0] == 1)return true;
        return false;
    }else{ //보
        // 보는 한쪽 끝 부분이 기둥 위에 있거나
        if((y-1 >= 0 && block[x][y-1][0] == 1) || (x+1 <= N && y-1 >= 0 && block[x+1][y-1][0] == 1))
            return true;
        // 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
        else if(x-1 >= 0 && x+1 <= N && block[x-1][y][1] == 1 && block[x+1][y][1] == 1)
            return true;
        return false;
    }
}
bool erase(){   
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k < 2; k++){
                if(block[i][j][k] == 1){
                    block[i][j][k] = 0;
                    if(!insert(i, j, k)){
                        block[i][j][k] = 1;
                        return false;
                    }
                    block[i][j][k] = 1;
                }
            }
        }
    }
    return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    
    for(int i = 0; i < build_frame.size(); i++){
        int x = build_frame[i][0],y = build_frame[i][1];
        if(build_frame[i][2] == 0) {//기둥       
            if(build_frame[i][3] == 1){// 설치
                if(insert(x, y, 0)){ // 성공
                    block[x][y][0] = 1;
                }
            } else{ // 삭제
                block[x][y][0] = 0;
                if(!erase()) block[x][y][0] = 1; // 실패
            }
        } else if(build_frame[i][2] == 1){ // 보
            if(build_frame[i][3] == 1){ // 설치
                if(insert(x, y, 1)) block[x][y][1] = 1; // 성공
            } else{ // 삭제
                block[x][y][1] = 0;
                if(!erase()) block[x][y][1] = 1; // 실패
            }
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k < 2; k++){
                if(block[i][j][k] == 1){
                    vector<int> tmp = {i,j,k};
                    answer.push_back(tmp);
                }
            }
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int> > res;
    vector<vector<int> > input = {
        {1,0,0,1},
        {1,1,1,1},
        {2,1,0,1},
        {2,2,1,1},
        {5,0,0,1},
        {5,1,0,1},
        {4,2,1,1},
        {3,2,1,1}
    };
    res = solution(5,input);
    for(int i=0;i<res.size();i++){
        cout << res[i][0] <<","<<res[i][1] <<"," <<res[i][2] <<endl;
    }
    return 0;
}
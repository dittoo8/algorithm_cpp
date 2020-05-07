#include <iostream>
#include <string>
#include <vector>
using namespace std;
int keysize,locksize,boardsize;
void rotateKey(vector<vector<int> > &key){
    vector<vector<int> > tmp(keysize,vector<int>(keysize));
    for(int j=keysize-1;j>=0;j--){
        for(int i=0;i<keysize;i++){
            tmp[i][j]=key[keysize-j-1][i];
        }
    }
    key=tmp;
}
bool putKey(int x, int y, vector<vector<int>> key, vector<vector<int>> board){
    for(int i=x;i<x+keysize;i++){
        for(int  j=y;j<y+keysize;j++){
            board[i][j]+=key[i-x][j-y];
        }
    }
    for(int i=keysize-1;i<=boardsize-keysize;i++){
        for(int j=keysize-1;j<=boardsize-keysize;j++){
            if(board[i][j]==1) continue;
            return false;
        }
    }
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    keysize = key.size();
    locksize = lock.size();
    boardsize = locksize+(keysize-1)*2;
    vector<vector<int> > board(boardsize,vector<int>(boardsize,0));
    for(int i=keysize-1;i<=boardsize-keysize;i++){
        for(int j=keysize-1;j<=boardsize-keysize;j++){
            board[i][j]=lock[i-keysize+1][j-keysize+1];
        }
    }
    for(int r=0;r<4;r++){
        for(int i=0;i<=boardsize-keysize;i++){
            for(int j=0;j<=boardsize-keysize;j++){
                if(putKey(i,j,key,board)){
                    return true;
                }
            }
        }
        rotateKey(key);
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int> > key;
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(0);
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(0);
    vector<int> v3;
    v3.push_back(0);
    v3.push_back(1);
    v3.push_back(1);
    key.push_back(v1);
    key.push_back(v2);
    key.push_back(v3);
    vector<vector<int> > lock;
    vector<int> v4;
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    vector<int> v5;
    v5.push_back(1);
    v5.push_back(1);
    v5.push_back(0);
    vector<int> v6;
    v6.push_back(1);
    v6.push_back(0);
    v6.push_back(1);
    lock.push_back(v4);
    lock.push_back(v5);
    lock.push_back(v6);
    cout << solution(key,lock) <<endl;
    return 0;
}
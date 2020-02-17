#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = false;
    while (flag == false) {
        bool visit[31][31] = {false, };
        flag = true;
        for (int i = 0; i <m-1;i++) {
            for (int j = 0; j < n-1; j++) {
                if (!board[i][j]) continue;
                if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i + 1][j]) &&(board[i][j] == board[i + 1][j + 1])) {
                    visit[i][j] = visit[i][j+1] = visit[i+1][j] = visit[i + 1][j + 1] = true;
                    flag = false;
                }
            }
        }
        for (int i = 0; i < m; i++) {   //제거
            for (int j = 0; j < n; j++) {
                if (visit[i][j]) {
                    answer++;
                    for (int k = i-1; k >=0; k--) {
                        board[k + 1][j] = board[k][j];
                        board[k][j] = 0;
                    }
                }
            }
        }
    }
    return answer;
}
int main(){
    vector<string> v;
    v.push_back("CCBDE");
    v.push_back("AAADE");
    v.push_back("AAABF");
    v.push_back("CCBBF");
    cout << solution(4,5,v) << endl;
    return 0;
}
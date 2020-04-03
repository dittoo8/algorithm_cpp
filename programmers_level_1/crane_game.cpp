#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
    int bSize= board.size();
    stack<int> st;
    for(int i=0;i<moves.size();i++){
        int j=0;
        while(!board[j][moves[i]-1]) {
            if (j== bSize-1) break;
            j++;
        }
        if(j <bSize && board[j][moves[i]-1]){
            int now = board[j][moves[i]-1];
            board[j][moves[i]-1]=0;
            if (!st.empty() && st.top()==now){
                st.pop();
                answer+=2;
            } else st.push(now);
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(0);
    vector<int> v2;
    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(3);
    vector<int> v3;
    v3.push_back(0);
    v3.push_back(2);
    v3.push_back(5);
    v3.push_back(0);
    v3.push_back(1);
    vector<int> v4;
    v4.push_back(4);
    v4.push_back(2);
    v4.push_back(4);
    v4.push_back(4);
    v4.push_back(2);
    vector<int> v5;
    v5.push_back(3);
    v5.push_back(5);
    v5.push_back(1);
    v5.push_back(3);
    v5.push_back(1);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    vector<int> m;
    m.push_back(1);
    m.push_back(5);
    m.push_back(3);
    m.push_back(5);
    m.push_back(1);
    m.push_back(2);
    m.push_back(1);
    m.push_back(4);
    cout << solution(v,m) <<endl;
    return 0;
}
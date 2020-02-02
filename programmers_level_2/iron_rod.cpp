#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> st;
    for(int i=0;i<arrangement.length();i++){
        if(arrangement[i] == '('){
            st.push(arrangement[i]);
        } else {
            st.pop();
            if(arrangement[i-1] == '(') {
                answer+= st.size();
            } else {
                answer+=1;
            }
        }
    }
    return answer;
}
int main(){

    cout << solution("()(((()())(())()))(())") << endl;
    return 0;
}
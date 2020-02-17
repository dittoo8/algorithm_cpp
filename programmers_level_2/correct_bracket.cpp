#include <iostream>
#include<string>
#include <iostream>
#include <stack>
using namespace std;
bool solution(string s)
{
    if (s[0]==')') return false;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if (s[i]=='(') {
            st.push('(');
        } else {
            if (st.empty()){
                return false;
            } else {
                st.pop();
            }
        }
        if (i==s.length()-1 && st.empty()) return true;
    }
    return false;
}
int main(){
    cout << solution("(()(") << endl;
    return 0;
}
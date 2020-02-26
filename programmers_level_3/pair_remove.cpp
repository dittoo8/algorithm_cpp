#include <iostream>
#include <string>
#include <stack>
using namespace std;
int solution(string s)
{   
    stack<char> st;
    
    for(int i=0;i<s.length();i++){
        if (st.empty()) st.push(s[i]);
        else if(st.top()==s[i]) st.pop();
        else if (st.top()!=s[i]){
            st.push(s[i]);
        }
    }
    if (st.size()==0){
        return 1;
    } else {
        return 0;
    }
}
int main(){
    cout << solution("baabaa") << endl;
    return 0;
}
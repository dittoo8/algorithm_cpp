#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
bool isRight(string p){
    stack<char> st;
    for(int i = 0; i < p.size(); i++)
    {
        if(p[i] == '(') {
            st.push(p[i]);
        } else {
            if(st.empty()){
                return 0;
            }
            st.pop();
        }
    }
    if(st.empty()){
        return true;
    } else{
        return 0;
    }
}
string solution(string p) {
    string answer = "";
    if (p == "") return answer;
    int op = 0;
    int cl = 0;
    string u,v;
    for(int i=0;i<p.length();i++){
        if (p[i]=='('){
            op++;
        } else {
            cl++;
        }
        if(op == cl) {
            u = p.substr(0, op+cl);
            v = p.substr(op+cl, p.size());    
            break;
        }
    }
    if(isRight(u)){
        answer += u;
        string temp = solution(v);
        answer += temp;
    } else {
        string temp = "(";
        string tempV = solution(v);
        temp +=tempV;
        temp += ")";
        string temp3 = u.substr(1, u.size()-2);
        for(int i=0;i<temp3.length();i++){
            if (temp3[i] == '(') {
                temp += ")";
            } else {
                temp += "(";
            }
        }
        answer = temp;
    }
    return answer;
}
int main(){

    cout << solution("(()())()") << endl;
    return 0;
}
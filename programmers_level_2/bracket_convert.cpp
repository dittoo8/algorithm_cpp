#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
string eraseU(string u){
    string newU = "";
    int lastIdx = u.length()-1;
    for(int i=1;i<lastIdx;i++){
        if(u[i]=='(') {
            newU+=')';
        } else {
            newU+='(';
        }
    }
    return newU;
}
bool correct(string u){
    stack<int> st;
    if (u[0]==')') return false;
    for(int i=0;i<u.length();i++){
        if (u[i]=='('){
            st.push(1);
        } else {
            if (st.empty()) return false;
            else st.pop();
        }
    }
    if (st.empty()) return true;
    return false;
}
bool balance (string p, int s, int e){
    int a=0,b=0;
    for(int i=s;i<=e;i++){
        if(p[i]=='(') a++;
        if(p[i]==')') b++;
    }
    if (a==b) return true;
    else return false;
}
string solution(string p) {
    if(p=="") return "";
    string u = "";
    string v = "";
    for(int i=1;i<p.length();i+=2){
        if (balance(p,0,i) && balance(p,i+1,p.length()-1)){
            u = p.substr(0,i+1);
            v = p.substr(i+1,p.length()-i+1);
            break;
        }
    }
    if (correct(u)){
        return u+=solution(v);
    } else {
        string temp = "(";
        temp+=solution(v);
        temp+=')';
        temp+=eraseU(u);
        return temp;
    }
}
int main(){

    cout << solution("(()())()") << endl;
    return 0;
}
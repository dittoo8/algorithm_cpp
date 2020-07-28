#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool ck;
    stack<int> st;
    string str;
    while(true){
        str="";
        while(!st.empty()) st.pop();
        ck = true;
        getline(cin,str);
        if (str==".") break;
        for(int i=0;i<str.length();i++){
            if (str[i]=='('){
                st.push(1);
            }else if (str[i]=='['){
                st.push(2);
            }else  if (str[i]==')'){
                if (!st.empty() && st.top() == 1){
                    st.pop();
                }else {
                    ck =false;
                    break;
                }
            }else if (str[i]==']'){
                if (!st.empty() && st.top() == 2){
                    st.pop();
                }else {
                    ck = false;
                    break;
                }
            }
        }
        if (st.empty() && ck){
            cout << "yes" << '\n';
        }else {
            cout << "no" << '\n';
        }
    }
    return 0;
}
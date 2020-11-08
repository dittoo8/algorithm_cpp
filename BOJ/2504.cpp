#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    stack<char> st;
    string str;
    bool ck = false;
    int ans = 0;
    int tmp = 1;
    cin >> str;
    for(int i=0;i<(int)str.length();i++){
        if(str[i] == '('){
            tmp*=2;
            st.push('(');
        }else if (str[i] == '['){
            tmp*=3;
            st.push('[');
        }else if (str[i] == ')'){
            if(st.empty() || st.top()!='('){
                ck = true;
                break;
            }
            if(str[i-1] == '('){
                ans+=tmp;
            }
            st.pop();
            tmp/=2;
        }else if (str[i] == ']'){
            if(st.empty() || st.top()!='['){
                ck = true;
                break;
            }
            if(str[i-1] == '['){
                ans+=tmp;
            }
            st.pop();
            tmp/=3;
        }
    }
    if(ck || !st.empty()){
        cout << 0 << '\n';
    }else cout << ans << '\n';
    return 0;
}
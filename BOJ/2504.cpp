#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    stack<int> sSt,bSt;
    stack<pair<int, int> > vSt;
    string str;
    int ans = 0;
    cin >> str;
    for(int i=0;i<(int)str.length();i++){
        if(str[i]=='('){
            sSt.push(i);
        }else if (str[i]=='['){
            bSt.push(i);
        }else if (str[i] == ')'){
            if(sSt.empty()){
                cout << 0 << '\n';
                return 0;
            }
            if(sSt.top() == i-1){
                vSt.push(make_pair(i,2));
                sSt.pop();
            }else {
                int tmp = 0;
                while(!vSt.empty() && sSt.top() <=vSt.top().first ){
                    tmp+=vSt.top().second;
                    vSt.pop();
                }
                tmp*=2;
                vSt.push(make_pair(sSt.top(),tmp));
                sSt.pop();
            }
        }else if (str[i]==']'){
            if(bSt.empty()){
                cout << 0 << '\n';
                return 0;
            }
            if(bSt.top() == i-1){
                vSt.push(make_pair(i,3));
                bSt.pop();
            }else {
                int tmp = 0;
                while(!vSt.empty() && bSt.top() <=vSt.top().first ){
                    tmp+=vSt.top().second;
                    vSt.pop();
                }
                tmp*=3;
                vSt.push(make_pair(bSt.top(),tmp));
                bSt.pop();
            }
        }
        if(sSt.empty() && bSt.empty()){
            while(!vSt.empty()){
                ans+=vSt.top().second;
                vSt.pop();
            }
        }
    }
    if(sSt.empty() && bSt.empty()){
        cout << ans << '\n';
    }else cout << 0 << '\n';
    return 0;
}
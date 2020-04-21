#include <iostream>
#include <sstream>
#include <string>
using namespace std;
void solve(string s){
    for(int i=(int)s.size()-2;i>=0;i--){
        if(s[i]==']') cout << "[]", i--;
        else if (s[i]=='&' || s[i]=='*') cout << s[i];
        else {
            cout <<' ';
            for(int j=0;j<=i;j++) cout << s[j];
            cout <<";\n";
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    getline(cin,str);
    stringstream ss(str);
    string datatype, val;
    ss >> datatype;
    while(ss >> val){
        cout << datatype;
        solve(val);
    }
    return 0;
}
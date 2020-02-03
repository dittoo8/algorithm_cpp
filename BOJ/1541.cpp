#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cin >> a;
    int res = 0;
    string temp = "";
    bool minus = false;
    for(int i=0;i<=a.size();i++){
        if(a[i] == '+' || a[i] =='-'||a[i]=='\0'){
            if(minus == true) res += -stoi(temp);
            else res += stoi(temp);
            temp = "";
            if(a[i]=='-') minus = true;
            continue;
        }
        temp += a[i];
    }
    cout << res << endl;
    return 0;
}
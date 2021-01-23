#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(true){
        string str;
        getline(cin, str);
        if (str == "END") break;
        reverse(str.begin(), str.end());
        cout << str << '\n';
    }
    return 0;
}
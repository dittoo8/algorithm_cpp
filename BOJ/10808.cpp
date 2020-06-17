#include <iostream>
#include <string>
using namespace std;
int main(){
    int a[27] = {0,};
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        a[str[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        cout << a[i] <<" " ;
    }
    return 0;
}
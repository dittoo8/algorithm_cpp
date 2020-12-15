#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str;
    int cnt = 1;
    getline(cin,str);
    for(int i=0;i<str.length();i++){
        if(str[i]==' ') cnt++;
    }
    if(str[0]==' ') cnt--;
    if(str[str.length()-1]==' ') cnt--;
    cout << cnt << '\n';
    return 0;
}
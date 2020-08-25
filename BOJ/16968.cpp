#include <iostream>
#include <string>
using namespace std;
int main(){
    int answer = 1;
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        int cnt;
        if (str[i]== 'c') {
            cnt = 26;
        }else cnt = 10;
        if (i>0 && str[i]== str[i-1]){
            cnt--;
        }
        answer*=cnt;
    }
    cout << answer << '\n';
    return 0;
}
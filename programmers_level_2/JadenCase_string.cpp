#include <iostream>
#include <string>
#include <vector>
using namespace std;
string solution(string s) {
    string answer = "";
    for(int i=0;i<s.length();i++){
        if(i==0 || s[i-1]==' '){
            answer+=toupper(s[i]);
        } else answer+=tolower(s[i]);
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << solution("3people unFollowed me") << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string solution(string s, int n) {
    string answer = "";
    for(int i=0;i<s.size();i++){
        if (s[i]==' ') {
            answer+=" ";
        }else if(islower(s[i])&& s[i]+n >'z'){
            answer+=s[i]+n-26;
        }else if (isupper(s[i])&&s[i]+n>'Z'){
            answer+=s[i]+n-26;
        }else answer+=s[i]+n;
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solution("a B z",4) <<endl;
    return 0;
}
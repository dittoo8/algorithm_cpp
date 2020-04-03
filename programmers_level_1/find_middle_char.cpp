#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    if (s.length()%2){
        //홀수
        answer = s.substr(s.length()/2,1);
    } else answer = s.substr(s.length()/2-1,2);
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solution("qwer")<<endl;
    return 0;
}
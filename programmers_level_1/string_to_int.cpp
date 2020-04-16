#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int solution(string s) {
    int answer = 0;
    int start=0;
    int last = 1;
    if (s[0]=='+'){
        start=1;
    }else if (s[0]=='-'){
        start=1;
        last=-1;
    }
    for(int i=start;i<s.length();i++){
        answer+=s[i]-'0';
        if (i== s.length()-1) break;
        answer*=10;
    }
    return answer*last;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solution("1234") <<endl;
    return 0;
}
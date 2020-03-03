#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(string s) {
    int len = s.size();
    int answer = len;
    for(int i = 1; i <= (len/2); i++) {
        string result = "";
        string temp = s.substr(0,i);
        int count = 1;    
        for(int j = i; j <= len; j+=i) {
            if(temp == s.substr(j,i)) {
                count++;
            }
            else {
                if(count == 1) {
                    result += temp;
                }
                else {
                    result += (to_string(count) + temp);
                }
                temp = s.substr(j,i);
                count = 1;
            }
        }
        if(len / i != 0) {
            result += s.substr((len/i) * i);
        }
        if(answer > result.size()) answer = result.size();
    }
    return answer;
}
int main(){
    cout << solution("abcabcdede") << endl;
    return 0;
}
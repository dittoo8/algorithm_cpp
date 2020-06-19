#include <iostream>
#include <string>
using namespace std;
bool d[2501][2501];
int solution(string s){
    int answer =1;
    //길이가 1인경우
    for(int i=0;i<s.length();i++) d[i][i]=true;
    //길이가 2인경우
    for(int i=0;i<s.length()-1;i++){
        if (s[i]==s[i+1]) {
            d[i][i+1] = true;
            answer = 2;
        }
    }
    // 길이가 3~문자열의 전체 길이까지
    for(int k=3;k<=s.length();k++){
        for(int i=0;i<=s.length()-k;i++){
            int j = i+k-1;
            if(s[i]==s[j]&& d[i+1][j-1]) {
                d[i][j]= true;
                if(answer < k) answer = k;
            }
        }
    }
    return answer;
}
int main(){
    cout << solution("abcdcba") <<endl;
    return 0;
}
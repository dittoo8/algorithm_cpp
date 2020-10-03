#include <iostream>

using namespace std;
int solution(int n){
    int answer = 0;

    string str = to_string(n);
    for(int i=0;i<str.length();i++){
        answer+=str[i]-'0';
    }

    return answer;
}
int main(){
    cout << solution(123) << endl;
    return 0;
}
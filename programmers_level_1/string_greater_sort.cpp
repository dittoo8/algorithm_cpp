#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
string solution(string s) {
    string answer = s;
    sort(answer.begin(),answer.end(),greater<char>());
    return answer;
}
int main(){
    cout << solution("Zbcdefg") << endl;

    return 0;
}
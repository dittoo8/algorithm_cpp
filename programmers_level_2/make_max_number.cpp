#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int firstIdx = 0;
    int lastIdx = k;
    int tempFirst = 0;
    int tempLast = k;
    while(answer.length() != number.length()-k){
        char max = '0';
        firstIdx = tempFirst;
        lastIdx = tempLast;
        // cout << "firstIdx : " << firstIdx << endl;
        // cout << "lastIdx : " << lastIdx << endl;
        for(int i=firstIdx;i <=lastIdx && lastIdx < number.length();i++){
            if(max < number[i]){
                max = number[i];
                tempFirst = i+1;
                // lastIdx += i;
            }
        }
        tempLast += 1;
        // cout << "max : " << max << endl;
        answer+=max;
    }
    
    return answer;
}
int main(){
    cout << solution("4177252841", 4) << endl;
}
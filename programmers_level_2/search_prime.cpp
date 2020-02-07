#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool checkNum(int i, string numbers){
    vector<bool> visited(numbers.size()+1);
    while(i){
        bool flag = false;
        int temp = i%10;
        for(int j=0;j<=numbers.size();j++){
            if(temp == numbers[j]-'0' && visited[j]==false) {
                flag = true;
                visited[j] = true;
                break;
            }
        }
        if(!flag) return false;
        i /=10;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(),numbers.end(),greater<int>());
    vector<bool> temp(stoi(numbers)+1, false);
    for(int i=2;i<=stoi(numbers); i++){
        if (!temp[i] && checkNum(i,numbers)) answer++;
        if(!temp[i]){
            for(int j=i;j<=stoi(numbers);j+=i) temp[j] = true;
        }
    }
    return answer;
}
int main(){
    cout << solution("17") << endl;
    return 0;
}
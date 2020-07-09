#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int cnt[10];
bool checkNum(int i){
    string s = to_string(i);
    int tmpcnt[10];
    memcpy(tmpcnt,cnt,sizeof(tmpcnt));
    for(int i=0;i<s.length();i++){
        tmpcnt[s[i]-'0']--;
        if(tmpcnt[s[i]-'0'] < 0) return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(),numbers.end(),greater<int>());
    for(int i=0;i<numbers.length();i++){
        cnt[numbers[i]-'0']++;
    }
    vector<bool> temp(stoi(numbers)+1, false);
    for(int i=2;i<=stoi(numbers); i++){
        if (!temp[i] && checkNum(i)) answer++;
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
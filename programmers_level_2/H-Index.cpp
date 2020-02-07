#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),greater<int>());
    while(answer < citations.size()){
        if(citations[answer] <=answer) break;
        answer ++;
    }
    return answer;
}
int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(0);
    v.push_back(6);
    v.push_back(1);
    v.push_back(5);
    cout << solution(v) << endl;
    return 0;
}
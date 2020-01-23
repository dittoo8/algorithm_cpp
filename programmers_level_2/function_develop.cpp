#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

#include <iostream>
using namespace std;

void solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;
    for(int i=0;i<progresses.size();i++){
        day.push_back(round((100-progresses[i])/speeds[i]));
    }
    int temp = day[0];
    int cnt = 0;
    for(int i=0;i<day.size();i++){
        if(temp < day[i]){
            answer.push_back(cnt);
            cnt= 1;
            temp = day[i];
        } else {
            cnt++;
        }
        if( i == day.size() - 1) {
            answer.push_back(cnt);
        }
    }
    
    for(int i=0;i<answer.size();i++){
        printf("%d ", answer[i]);
    }
    // return answer;
}
int main(){
    vector<int> progresses;
    vector<int> speeds;
    progresses.push_back(93);
    progresses.push_back(30);
    progresses.push_back(55);
    speeds.push_back(1);
    speeds.push_back(30);
    speeds.push_back(5);
    solution(progresses, speeds);
    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> list(n+1,1);
    int answer = 0;
    for (int i=0;i<lost.size();i++) {
        list[lost[i]]--;
    }
    for (int i=0;i<reserve.size();i++) {
        list[reserve[i]]++;
    }
    list[0]=0;
    for(int i=1;i<list.size();i++){
        if(list[i]==0){
            if(list[i-1]==2) {
                list[i-1]--;
                list[i]++;
            } else if (list[i+1]==2) {
                list[i+1]--;
                list[i]++;
            }
        }
    }
    for(int i=1;i<list.size();i++) {
        if(list[i]>0){
            answer++;
        }
    }
    return answer;
}
int main(){
    vector<int> v1 = {2,4};
    vector<int> v2 = {1,3,5};
    cout << solution(5,v1,v2) <<endl;
    return 0;
}
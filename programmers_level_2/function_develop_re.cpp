#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    priority_queue<int> pq;
    for(int i=0;i<progresses.size();i++){
        int tmp = 100 - progresses[i];
        if (tmp%speeds[i]==0){
            tmp= tmp/speeds[i]; 
        }else {
            tmp= tmp/speeds[i]; 
            tmp++;
        }
        if(!pq.empty() && pq.top() < tmp){
            answer.push_back((int)pq.size());
            while(!pq.empty()) pq.pop();
        }
        pq.push(tmp);
    }
    if (!pq.empty()) answer.push_back((int)pq.size());
    return answer;
}
int main(){
    vector<int> progresses = {93,30,55};
    vector<int> speeds = {1,30,5};
    vector<int> res;
    res = solution(progresses, speeds);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}
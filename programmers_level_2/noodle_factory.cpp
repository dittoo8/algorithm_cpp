#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int idx = 0;
    int answer =0;
    priority_queue<int, vector<int>, less<int> > pq;
    while(stock < k){
        for(int i=idx;i<dates.size()&& stock >=dates[i];i++){
            pq.push(supplies[i]);
            idx = i+1;
        }
        stock+=pq.top();
        pq.pop();
        answer++;
    }
    return answer;
}
int main(){
    vector<int> dates;
    dates.push_back(4);
    dates.push_back(10);
    dates.push_back(15);
    vector<int> supplies;
    supplies.push_back(20);
    supplies.push_back(5);
    supplies.push_back(10);
    cout << solution(4,dates,supplies,30) << endl;
    return 0;
}
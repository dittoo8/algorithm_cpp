#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0;i<scoville.size();i++){
        if(scoville[i] < K) {
            pq.push(scoville[i]);
        }
    }
    while(pq.top() < K){
        if(pq.size() ==1) return -1;
        answer++;
        int a, b;
        a = pq.top();
        pq.pop();
        if (pq.size()==0) {
            answer = -1;
            break;
        }
        b = pq.top();
        pq.pop();
        pq.push(a+(b*2));
    }
    return answer;
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(9);
    v.push_back(10);
    v.push_back(12);
    cout << solution(v,7) << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int max_size = 0;
    queue<int> q;
    int now = 0;
    for(int i=0;i<truck_weights.size();i++){
        now = truck_weights[i];
        while(1){
            if(q.empty()){
                q.push(now);
                max_size+=now;
                answer++;
                break;
            }else if (q.size() == bridge_length){
                max_size-=q.front();
                q.pop();        
            } else {
                if(max_size + now >weight){
                    q.push(0);
                    answer++;
                } else {
                    q.push(now);
                    max_size+=now;
                    answer++;
                    break;
                }
            }
        }
    }
    return answer+bridge_length;
}
int main(){
    vector<int> truck_weights;
    truck_weights.push_back(7);
    truck_weights.push_back(4);
    truck_weights.push_back(5);
    truck_weights.push_back(6);
    cout << solution(2,10,truck_weights) << endl;
    return 0;
}
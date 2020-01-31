#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solution(vector<int> heights) {
    vector<int> answer;
    int Vsize = heights.size();
    answer.resize(Vsize,0);
    for(int i=1;i<heights.size();i++){
        for(int j=i;j>=0;j--){
            if (heights[j]> heights[i]) {
                answer[i] = j+1;
                break;
            }
        }
    }
    // return answer;
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << " " ;
    }
}
int main(){
    vector<int> heights;
    heights.push_back(6);
    heights.push_back(9);
    heights.push_back(5);
    heights.push_back(7);
    heights.push_back(4);
    solution(heights);
    return 0;
}
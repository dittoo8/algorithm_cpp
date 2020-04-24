#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> weight) {
    int answer = 1;
    sort(weight.begin(),weight.end());
    for(int i=0;i<weight.size();i++){
        if (answer < weight[i]) break;
        answer+=weight[i];
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(6);
    v.push_back(2);
    v.push_back(7);
    v.push_back(30);
    v.push_back(1);
    cout << solution(v) <<endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left_point = 0; int right_point = people.size() - 1; 
    sort(people.begin(), people.end(), greater<int>());
    
    while(left_point < right_point + 1) {
        if (people[left_point] + people[right_point] <= limit) 
            right_point--;
        left_point++;
        answer++;
    }
    
    return answer;
}
int main(){
    vector<int> v;
    v.push_back(70);
    v.push_back(50);
    v.push_back(80);
    v.push_back(50);
    cout << solution(v,100) <<endl;
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(),d.end());
    for(int i=0;i<d.size();i++){
        if(budget == 0 || budget < d[i]) {
                break;
            }
        budget -= d[i];
        answer++;
    }
    return answer;
}

int main(){
    vector<int> d;
    d.push_back(1);
    d.push_back(3);
    d.push_back(2);
    d.push_back(5);
    d.push_back(4);
    printf("%d", solution(d, 9));
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int l=0, h = 0;
    for(int i=0;i<budgets.size();i++){
        if (budgets[i]>h) h = budgets[i];
    }
    int mid;
    while(l <=h){
        mid = (l+h)/2;
        int sum = 0;
        for(int i=0;i<budgets.size();i++){
            if (budgets[i]>mid){
                sum+=mid;
            } else sum+=budgets[i];
        }
        if(sum <=M){
            answer = max(answer,mid);
            l = mid+1;
        } else {
            h = mid-1;
        }
    }
    return answer;
}
int main(){
    vector<int> v;
    v.push_back(120);
    v.push_back(110);
    v.push_back(140);
    v.push_back(150);
    cout << solution(v, 485) << endl;
    return 0;
}
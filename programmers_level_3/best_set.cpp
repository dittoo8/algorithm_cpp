#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int div = s/n;
    if(div==0){
        answer.push_back(-1);
    }else {
        int rest = s%n;
        answer.resize(n,div);
        for(int i=n-1;i>=n-rest;i--){
            answer[i]++;
        }
    }
    return answer;
}
int main(){
    vector<int> res = solution(2,9);
    for(int i=0;i<res.size();i++){
        cout << res[i] <<" ";
    }
    return 0;
}
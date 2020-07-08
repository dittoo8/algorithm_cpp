#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n = (int)prices.size();
    answer.resize(n,0);
    int now;
    for(int i=0;i<n-1;i++){
        now = prices[i];
        for(int j=i+1;j<n;j++){
            if(prices[j]<now) {
                answer[i]=j-i;
                break;
            }
        }
        if(answer[i]==0) answer[i]=n-i-1;
    }
    return answer;
}
int main(){
    vector<int> v = {1,2,3,2,3};
    vector<int> res  = solution(v);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    if(n==1) return answer;
    for(int i=2;i<=n;i++){
        vector<int> tmp = answer;
        answer.push_back(0);
        for(int j=tmp.size()-1;j>=0;j--){
            if (tmp[j]==0) answer.push_back(1);
            else answer.push_back(0);
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> res;
    res = solution(3);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
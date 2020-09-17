#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> st;
    for(int i=0;i<numbers.size()-1;i++){
        for(int j=i+1;j<numbers.size();j++){
            st.insert(numbers[i]+numbers[j]);
        }
    }
    for(auto it = st.begin();it!=st.end();it++){
        answer.push_back(*it);
    }
    sort(answer.begin(),answer.end());
    return answer;
}
int main(){
    vector<int> v = {2,1,3,4,1};
    vector<int> res = solution(v);
    for(int i=0;i<res.size();i++){
        cout << res[i] << ' ';
    } 
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n = (int)prices.size();
    answer.resize(n);
    stack<int> st;
    for(int i=0;i<prices.size();i++){
        while(!st.empty() &&prices[st.top()] > prices[i]){
            answer[st.top()] = i-st.top();
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        answer[st.top()] = n-st.top()-1;
        st.pop();
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
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int n, top;
int hi[100002];
stack<int> st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int tempMax = 0;
    for(int i=0;i<n;i++){
        cin >> hi[i];
    }
    for(int i=0;i<=n;i++){
        while(!st.empty() && hi[st.top()] > hi[i]){
            int dist;
            top = st.top();
            st.pop();
            if(st.empty()) dist = i;
            else dist = i- st.top() - 1;
            //현재 인덱스와의 거리 계산
            tempMax = max(tempMax, hi[top]*dist);
        }
        st.push(i);
    }
    cout << tempMax ;

    return 0;
}
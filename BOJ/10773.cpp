#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> st;
    int k,num,ans=0;
    cin >> k;
    while(k--){
        cin >> num;
        if(num == 0){
            st.pop();
        }else {
            st.push(num);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout << ans << '\n';
    return 0;
}
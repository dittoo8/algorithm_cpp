#include <iostream>
#include <stack>
#define MAX 100001
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    long long ans, a[MAX];
    while(true){
        ans = 0;
        stack<long long> st; 
        cin >> n;
        if (n==0) break;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>a[i]){
                long long h = a[st.top()];
                st.pop();
                long long w = i;
                if (!st.empty()) w = (i-st.top()-1);
                if (h*w > ans) ans = h*w;
            }
            st.push(i);
        }
        while(!st.empty()){
            long long h =a[st.top()];
            st.pop();
            long long w = n;
            if (!st.empty()){
                w = n-st.top()-1;
            }
            if (w*h > ans) ans = w*h;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
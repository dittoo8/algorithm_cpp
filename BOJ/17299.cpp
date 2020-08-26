#include <cstdio>
#include <stack>
#define MAX 1000001
using namespace std;
int cnts[MAX];
int main(){
    int a[MAX], ans[MAX];
    stack<int> st;
    int n;
    scanf("%d", &n);
    fill(&ans[0], &ans[n]+1, -1);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        cnts[a[i]]++;
    }
    for(int i=0;i<n;i++){
        while(!st.empty() && cnts[a[st.top()]]< cnts[a[i]]){
            ans[st.top()]= a[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i=0;i<n;i++){
        printf("%d ", ans[i]);
    }
    return 0;
}
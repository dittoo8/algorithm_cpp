#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int num[n];
    vector<char> ret;
    stack<int> st;
    for (int i=0; i<n; i++) {
        scanf("%d", &num[i]);
    }
    int idx=0;
    for (int i=1; i<=n; i++) {
        st.push(i);
        ret.push_back('+');
        while (!st.empty() && st.top() == num[idx]) {
            idx++;
            st.pop();
            ret.push_back('-');
        }
    }
    
    if (!st.empty()) {
        printf("NO\n");
    } else {
        for(int i=0;i<ret.size();i++){
            printf("%c\n",ret[i]);
        }
    }
    return 0;
}
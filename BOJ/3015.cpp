#include <iostream>
#include <stack>
#define MAX 500001
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    stack<pair<int, int> > st;
    int n;
    cin >> n;
    long long answer = 0;
    long long a[MAX];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        int h = a[i];
        int cnt = 1;
        while(!st.empty()){
            if (st.top().first <= a[i]){
                answer += (long long)st.top().second;
                if( st.top().first == a[i]){
                    cnt += st.top().second;
                }
                st.pop();
            }else break;
        }
        if(!st.empty()){
            answer += 1;
        }
        st.push(make_pair(h,cnt));
    }
    cout << answer << '\n';
    return 0;
}
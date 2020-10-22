#include <iostream>
#include <stack>
#include <algorithm>
#define MAX 1001
using namespace std;
int ans,visit[MAX], adj[MAX];
bool finish[MAX];
stack<int> st;
int dfs(int x){
    visit[x] = x;
    st.push(x);
    int next = adj[x];
    if(!visit[next]){
        visit[x] = min(visit[x],dfs(next));
    }else if (!finish[next]){
        visit[x] = min(visit[x], visit[next]);
    }
    if(visit[x]==x){
        ans++;
        while(true){
            int t = st.top();
            st.pop();
            finish[t] = true;
            if (t == x) break;
        }
    }
    return visit[x];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc,n;
    cin >> tc;
    while(tc--){
        cin >> n;
        ans = 0;
        while(!st.empty()) st.pop();
        fill(&finish[0], &finish[n]+1,0);
        fill(&visit[0],&visit[n]+1,0);
        int num;
        for(int i=1;i<=n;i++){
            cin >> adj[i];
        }
        for(int i=1;i<=n;i++){
            if(!finish[i]){
                dfs(i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
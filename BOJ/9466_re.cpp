#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int n, a[MAX],cnt;
bool visit[MAX],finish[MAX];
void dfs(int x){
    visit[x] = true;
    int next = a[x];
    if(visit[next]){
        if(!finish[next]){
            for(int tmp = next;tmp!=x;tmp=a[tmp]) cnt++;
            cnt++;
        }
    }else dfs(next);
    finish[x]= true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n;
        cnt = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        fill(&visit[0], &visit[n]+1,0);
        fill(&finish[0],&finish[n]+1,0);
        for(int i=1;i<=n;i++){
            if(!visit[i]) dfs(i);
        }
        cout << n-cnt << '\n';
    }
    return 0;
}
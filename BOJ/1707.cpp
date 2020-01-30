#include <iostream>
#include <vector>
using namespace std;
int t;
int c[20002];
int v, e;
vector<int> a[20002];
bool dfs(int x, int check){
    c[x] = check;
    //c[x]에 현재 색을 칠함,
    for(int i=0;i<a[x].size();i++){
        int next = a[x][i];
        if (c[next]==0) {
            //아직 안칠한 경우,
            if(!dfs(next,-check)){
                //현재 색과 다른 색으로 칠했는데 false 나온 경우
                return false;
            }
        } else if(c[next] == c[x]) {
            return false;
        }
    }
    return true;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> v >> e;
        for(int i=1;i<=v;i++){
            a[i].clear();
            c[i] = 0;
        }
        for(int i=0;i<e;i++){
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        bool ans = 1;
        for( int i=1;i<=v;i++){
            if(c[i] == 0) {
                if (!dfs(i,1)) {
                    ans = false;
                    //하나라도 false 나오면 실패
                    break;
                }
            }
        }
        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        //1부터 시작, 1에 1을 칠함
    }
    return 0;
}
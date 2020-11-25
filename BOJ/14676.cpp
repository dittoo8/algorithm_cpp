#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;
int n,m,k;
vector<int> adj[MAX];
int inDegree[MAX], construct[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    int u,v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }
    int op,a;
    bool pass = true;
    for(int i=0;i<k;i++){
        cin >> op >> a;
        if (op == 1){ // 만들기
            if(inDegree[a]==0) { // 만들 수 있음
                construct[a]++;
                if(construct[a]==1){ // 처음 만든 정점일때
                    for(int t = 0; t< adj[a].size();t++){
                        inDegree[adj[a][t]]--;
                    }
                }
            }else {
                pass= false;
            }
        }else { //삭제하기
            if(construct[a] > 0){ //삭제할 수 있음
                construct[a]--;
                if(construct[a]==0){ // 모든 a를 삭제했을 때
                    for(int t = 0; t< adj[a].size();t++){
                        inDegree[adj[a][t]]++;
                    }
                }
            }else {
                pass= false;
            }
        }
    }
    if(pass){
        cout << "King-God-Emperor" <<'\n';
    }else{
        cout << "Lier!" << '\n';
    }
    return 0;
}
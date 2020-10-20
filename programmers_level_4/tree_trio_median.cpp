#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int> > node;
vector<bool> visit;
int leaf,max_len,cnt;
void dfs(int cur, int len, bool T){
    if(visit[cur] == true) return;
    if(T == false){
        if(len > max_len){
            leaf= cur;
            max_len = len;
        }
    }else {
        if(len > max_len){
            leaf = cur;
            cnt = 1;
            max_len = len;
        }else if (len == max_len) cnt++;
    }
    visit[cur] = true;
    for(int i=0;i<node[cur].size();i++){
        int next = node[cur][i];
        dfs(next,len+1,T);
    }
}
void func(int start, int n , bool T){
    cnt = 0;
    max_len = 0;
    visit.assign(n+1,false);
    dfs(start,0,T);
}
int solution(int n, vector<vector<int>> edges) {
    node.resize(n+1);
    visit.resize(n+1,false);
    for(int i=0;i<edges.size();i++){
        node[edges[i][0]].push_back(edges[i][1]);
        node[edges[i][1]].push_back(edges[i][0]);
    }
    func(1,n,false);
    func(leaf,n,true);
    if (cnt>=2) return max_len;
    else {
        func(leaf,n,true);
        if(cnt >=2) return max_len;
        else return max_len-1;
    }
}
int main(){
    vector<vector<int> > v;
    v = {{1,5},{2,5},{3,5},{4,5}};
    cout << solution(5,v) << endl;
    return 0;
}
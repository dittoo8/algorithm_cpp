#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 20001
using namespace std;
bool visited[MAX];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> adj[MAX];
    for(int i=0;i<edge.size();i++){
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    visited[1] = true;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int qS = q.size();
        answer = qS;
        while(qS--){
            int x = q.front();
            q.pop();
            for(int i=0;i<adj[x].size();i++){
                int next = adj[x][i];
                if(visited[next]) continue;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return answer;
}
int main(){
    vector<vector<int> > v = {
        {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}
    };
    cout << solution(6, v) << endl;
    return 0;
}
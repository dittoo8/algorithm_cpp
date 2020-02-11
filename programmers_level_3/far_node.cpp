#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dist[20002];
int solution(int n, vector<vector<int> > edge) {
    int answer = 0;
    queue<int> q;
    q.push(1);
    dist[1]=0;
    int maxDist = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<edge.size();i++){
            if (edge[i][0]==now && dist[edge[i][1]]==0){
                q.push(edge[i][1]);
                dist[edge[i][1]]= dist[now]+1;
                maxDist = dist[edge[i][1]];
                
            } else if (edge[i][1]==now && dist[edge[i][0]]==0){
                q.push(edge[i][0]);
                dist[edge[i][0]]= dist[now]+1;
                maxDist = dist[edge[i][0]];
                
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(dist[i]==maxDist) {
            answer++;
            // cout << i << "," ;
        }
    }
    return answer;
}
int main(){
    vector<vector <int> > v;
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(6);
    vector<int> v2;
    v2.push_back(4);
    v2.push_back(3);
    vector<int> v3;
    v3.push_back(3);
    v3.push_back(2);
    vector<int> v4;
    v4.push_back(1);
    v4.push_back(3);
    vector<int> v5;
    v5.push_back(1);
    v5.push_back(2);
    vector<int> v6;
    v6.push_back(2);
    v6.push_back(4);
    vector<int> v7;
    v7.push_back(5);
    v7.push_back(2);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    v.push_back(v6);
    v.push_back(v7);
    cout << solution(6,v) << endl;
    return 0;
}
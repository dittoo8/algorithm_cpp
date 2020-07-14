#include <iostream>
#include <vector>
#include <queue>
#define MAX 10000000
using namespace std;
int res[51];
vector<pair<int, int> > adj[51];
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    fill(&res[0],&res[50]+1,MAX);
    priority_queue<pair<int, int> > pq;
    for(int i=0;i<road.size();i++){
        adj[road[i][0]].push_back(make_pair(road[i][1],road[i][2]));
        adj[road[i][1]].push_back(make_pair(road[i][0],road[i][2]));
        
    }
    res[1]=0;
    pq.push(make_pair(0,1));
    while(!pq.empty()){
        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        if (dist > res[now]) continue;
        for(int i=0;i<adj[now].size();i++){
            int next= adj[now][i].first;
            int nextDist = dist + adj[now][i].second;
            if(nextDist < res[next]){
                res[next] = nextDist;
                pq.push(make_pair(-nextDist,next));
            }
        }
    }
    for(int i=1;i<=N;i++){
        if (res[i]<=K) answer++;
    }
    return answer;
}
int main(){
    vector<vector<int> > v = {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
    cout << solution(5,v,3) <<endl;
    return 0;
}
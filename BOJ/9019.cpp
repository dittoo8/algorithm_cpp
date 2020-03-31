#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> Case(N);
    for(int i=0; i<N; i++){
        cin >> Case[i].first >> Case[i].second;
    }
    for(int i=0; i<N; i++){
        queue<pair<int, string>> q;
        vector<bool> visited(10000, 0);
        q.push(make_pair(Case[i].first, ""));
        visited[Case[i].first] = true;
        while(!q.empty()) {
            int now = q.front().first;
            string way = q.front().second;
            q.pop();
            
            if(now == Case[i].second) {
                cout << way << endl;
                break;
            }
            else {
                int next = (now*2) % 10000;
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(make_pair(next, way+"D"));
                }
                if(now == 0) {next = 9999;}
                else {next = now-1;}
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(make_pair(next, way+"S"));
                }
                if(now != 0) {
                    next = (now%1000)*10 + now/1000 ;
                    if(!visited[next]) {
                        visited[next] = true;
                        q.push(make_pair(next, way+"L"));
                    }
                    next = (now/10) + (now%10)*1000;
                    if(!visited[next]) {
                        visited[next] = true;
                        q.push(make_pair(next, way+"R"));
                    }
                }
            }
        }
    }
}
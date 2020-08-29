#include <iostream>
#include <queue>
#define MAX 201
using namespace std;
bool ans[MAX];
bool check[MAX][MAX];
int cap[3];
int from[] = {0,0,1,1,2,2}, to[]={1,2,0,2,0,1};
int main(){
    cin >> cap[0] >> cap[1] >> cap[2];
    int sum = cap[2];
    queue<pair<int, int> > q;
    q.push(make_pair(0,0));
    check[0][0] = true;
    ans[cap[2]]= true;
    while(!q.empty()){
        int cur[3];
        cur[0] = q.front().first;
        cur[1] = q.front().second;
        cur[2] = sum-cur[0]-cur[1];
        q.pop();
        for(int k=0;k<6;k++){
            int next[3] = {cur[0],cur[1], cur[2]};
            next[to[k]]+=next[from[k]];
            next[from[k]]= 0;
            if (next[to[k]]>= cap[to[k]]){
                next[from[k]] = next[to[k]]- cap[to[k]];
                next[to[k]]= cap[to[k]];
            }
            if (!check[next[0]][next[1]]){
                check[next[0]][next[1]] = true;
                q.push(make_pair(next[0],next[1]));
                if (next[0]==0){
                    ans[next[2]] = true;
                }
            }
        }
    }
    for(int i=0;i<=cap[2];i++){
        if (!ans[i]) continue;
        cout << i << ' ';
    }
    return 0;
}
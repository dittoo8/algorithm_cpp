#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n,k;
vector<int> a[102];
int check[102];
pair<int ,int> input;
int bfs(int x){

    queue<int> q;
    check[x]= true;
    q.push(x);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0;i<a[curr].size();i++){
            if(!check[a[curr][i]]) {
                if(a[curr][i] == input.second) return check[curr];
                q.push(a[curr][i]);
                check[a[curr][i]]= check[curr] + 1;
                // printf("check[%d] = check[%d] + 1, %d\n",a[curr][i],curr,check[a[curr][i]]);
            }
        }
        
    }



    return -1;
}
int main(){
    scanf("%d", &n);
    scanf("%d %d", &input.first, &input.second);
    scanf("%d", &k);
    while(k--){
        int c, d;
        scanf("%d %d", &c, &d);
        a[c].push_back(d);
        a[d].push_back(c);
    }

    printf("%d", bfs(input.first));

    return 0;
}
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int a, b, c;
vector<int> v;
queue<pair<int, int> > q;
bool ck[201][201];
void pour(int x, int y){
    if(!ck[x][y]){
        ck[x][y]= true;
        q.push(make_pair(x,y));
    }
}
void bfs(){
    q.push(make_pair(0,0));
    ck[0][0] = true;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        int z = c-x-y; q.pop();
        if(!x) v.push_back(z);
        int w = min(x, b-y);
        pour(x-w,y+w);
        w= min(x,c-z);
        pour(x-w,y);
        w= min(y,a-x);
        pour(x+w,y-w);
        w=min(y,c-z);
        pour(x,y-w);
        w=min(z,a-x);
        pour(x+w,y);
        w=min(z,b-y);
        pour(x,y+w);

    }
}
int main(){
    scanf("%d %d %d", &a, &b, &c);
    bfs();
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    return 0;
}
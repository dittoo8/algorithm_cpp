#include <cstdio>
#include <queue>

using namespace std;
int map[102];
int c[102];
int n,m;
int main(){
    for(int i=1;i<=100;i++){
        map[i] = i;
        c[i] = -1;
    }
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        map[a] = b;
    }
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        map[a] = b;
    }
    c[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if (now == 100){
            printf("%d", c[now]);
            return 0;
        }
        for(int i=1;i<=6;i++){
            int next = now+i;
            if(c[map[next]]==-1 && next <=100){
                c[map[next]] = c[now]+1;
                q.push(map[next]);
            }
        }
            
    }
    
    return 0;
}
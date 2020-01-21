#include <cstdio>
#include <vector>
using namespace std;
int n,k;
int cnt;
vector<int> a[102];
bool c[102];
void dfs(int x){
    cnt++;
    for(int i=0;i<a[x].size();i++){
        if(!c[a[x][i]]) {
            c[a[x][i]] = 1;
            dfs(a[x][i]);
        }
    }
}
int main(){
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i=0;i<k;i++){
        int b, c;
        scanf("%d %d", &b, &c);
        a[b].push_back(c);
        a[c].push_back(b);
    }
    c[1] = 1;
    dfs(1);
    printf("%d", cnt-1);
    return 0;
}

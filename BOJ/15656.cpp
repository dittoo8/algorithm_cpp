#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<int> a;
vector<int> res;
void dfs(int len){
    if(len == m){
        for(int i=0;i<m;i++){
            printf("%d ", res[i]);
        }
        printf("\n");
        return;
    }else {
        for(int i=0;i<n;i++){
                res.push_back(a[i]);
                dfs(len+1);
                res.pop_back();
        }
    }
}
int main(){
    scanf("%d %d",&n, &m);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d", &temp);
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    dfs(0);
    return 0;
}
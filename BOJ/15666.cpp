#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> res,num;
void solve(int len,int cur){
    if(len ==m){
        for(int i=0;i<m;i++){
            printf("%d ",res[i]);
        }
        printf("\n");
        return;
    }else{
        bool used[10001]={false,};
        for(int i=cur;i<n;i++){
            if(!used[num[i]]){
                used[num[i]]=true;
                res[len]=num[i];
                solve(len+1,i);
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    res.resize(m);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d", &temp);
        num.push_back(temp);
    }
    sort(num.begin(),num.end());
    solve(0,0);
    return 0;
}
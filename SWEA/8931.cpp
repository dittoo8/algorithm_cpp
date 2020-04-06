#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int tc;
    vector<int> v;
    scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        int res=0,n;
        scanf("%d",&n);
        v.clear();
        for(int j=0;j<n;j++){
            int tmp;
            scanf("%d",&tmp);
            if(tmp ==0){
                v.pop_back();
            }else v.push_back(tmp);
        }
        for(int j=0;j<v.size();j++){
            res+=v[j];
        }
        printf("#%d %d",i,res);
    }
    return 0;
}
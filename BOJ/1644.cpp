#include <cstdio>
#include <vector>
using namespace std;
bool ck[4000002] = {false,};
int main(){
    vector<int> v;
    int n,ans=0;
    scanf("%d", &n);
    for(int i=2;i*i<=n;i++){
        if(!ck[i]){
            for(int j=i*i;j<=n;j+=i){
                ck[j]=true;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(!ck[i]) v.push_back(i);
    }
    int l=0;
    int r=0;
    int sum=0;
    int k = (int)v.size();
    while(true){
        if (sum>=n){
            sum-=v[l];
            l++;
        }else {
            if(r==k) break;
            sum+=v[r];
            r++;
        }
        if(sum==n) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
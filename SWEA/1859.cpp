#include <iostream>
using namespace std;
int num[1000002];
int main(){
    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++){
        int n;
        long long res=0;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &num[i]);
        }
        int mx = num[n-1];
        for(int i=n-1;i>=0;i--){
            if (mx >= num[i]){
                res+= mx-num[i];
            }else mx = num[i];
        }
        printf("#%d %lld\n", t,res);
    }
}
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int t=1;t<=tc;t++){
        int mx=0,mn=1e8+1;
        int num;
        int tmp=0;
        for(int i=0;i<10;i++){
            tmp = 0;
            cin >> num;
            while(num>0){
                tmp+=num%10;
                num/=10;
            }
            mx = max(mx,tmp);
            mn = min(mn,tmp);
        }
        printf("#%d %d %d\n",t,mx,mn);
    }
    return 0;
}
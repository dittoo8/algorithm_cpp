#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,a[1001];
    cin >> n;
    for(int i=0;i<n;i++){
        int k,avg=0,t=0;
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> a[j];
            avg+=a[j];
        }
        avg/=k;
        for(int j=0;j<k;j++){
            if (a[j] > avg){
                t++;
            }
        }
        float ans = 100*(double)t/(double)k;
        printf("%0.3f%%\n", ans);
    }
    return 0;
}
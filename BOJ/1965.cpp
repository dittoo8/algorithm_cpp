#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,a[1001],d[1001],mx=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    fill(&d[0], &d[n],1);
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[j]>= a[i]) continue;
            if(d[j]+1>d[i]){
                d[i]=d[j]+1;
            }
        }
        if(d[i] > mx) mx = d[i];
    }
    cout << mx << '\n';
    return 0;
}
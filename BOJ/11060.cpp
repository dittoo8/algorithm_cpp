#include <iostream>
#include <algorithm>
#define MAX 1002
using namespace std;
int n;
int a[MAX],d[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fill(&d[0], &d[MAX-1]+1,1000000);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    d[1]=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=i+a[i]&&j<=n;j++){
            d[j] = min(d[j],d[i]+1);
        }
    }
    if (d[n]==1000000){
        cout << -1 << '\n';
    }else cout << d[n] << '\n';
    return 0;
}
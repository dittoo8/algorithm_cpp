#include <iostream>
using namespace std;
int d[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    d[0]=1;
    for(int i=1;i<=3;i++){
        for(int j=i;j<=10000;j++){
            d[j]+=d[j-i];
        }
    }
    
    while (T--) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
    return 0;
}
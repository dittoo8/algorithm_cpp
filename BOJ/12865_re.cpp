#include <iostream>
#include <algorithm>
using namespace std;
int w[101],v[101],d[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=k;j>=1;j--){
            if (w[i] <=j){
                d[j] = max(d[j], d[j-w[i]]+v[i]);
            }
        }
    }
    cout << d[k] << '\n';
    return 0;
}
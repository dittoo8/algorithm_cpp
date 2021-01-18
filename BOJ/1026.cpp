#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a[51], b[51];
    int n,ans=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    reverse(b,b+n);
    for(int i=0;i<n;i++){
        ans+= a[i]*b[i];
    }
    cout << ans << '\n';
    return 0;
}
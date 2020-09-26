#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc,n,m,a,b;
    cin >> tc;
    while(tc--){
        cin >>  n >> m;
        for(int i=0;i<m;i++){
            cin >> a >> b;
        }
        cout << n-1 << '\n';
    }
    return 0;
}
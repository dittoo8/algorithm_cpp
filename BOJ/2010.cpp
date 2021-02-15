#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,sum=1;
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        sum+=k-1;
    }
    cout << sum << '\n';
    return 0;
}
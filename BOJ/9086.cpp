#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string x;
    for(int i=0;i<n;i++){
        cin >> x;
        cout << x[0]<< x[x.length()-1] << '\n';
    }
    return 0;
}
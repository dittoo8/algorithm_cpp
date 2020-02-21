#include <iostream>
using namespace std;
int main(){
    int n;
    int d[100002] = {1,3};
    cin >> n;
    for(int i=2;i<=n;i++){
        d[i] = (d[i-1]*2 +d[i-2])%9901;
    }
    cout << d[n] << endl;
    return 0;
}

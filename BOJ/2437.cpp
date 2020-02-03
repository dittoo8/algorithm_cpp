#include <iostream>
#include <algorithm>
using namespace std;
int num[1002];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    sort(num, num+n);
    int cnt = 1;
    for(int i=0;i<n;i++){
        if (cnt < num[i]) break;
        cnt += num[i];
    }
    cout << cnt <<endl;

    return 0;
}
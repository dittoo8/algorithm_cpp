#include <iostream>
#include <algorithm>
using namespace std;
int d[1002];
int a[1002];
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        d[i] = 1;
        for(int j=0;j<i;j++){
            if(a[j] > a[i] && d[j] + 1 > d[i]){
                d[i] = d[j] + 1;
            }
        }
    }
    int res = 0;
    for(int i = 0;i<n;i++){
        res = max(res,d[i]);
    }
    cout << res <<endl;

    return 0;
}
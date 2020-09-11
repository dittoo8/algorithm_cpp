#include <iostream>
#include <algorithm>
#define MAX 15000002
using namespace std;
int d[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a, b;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        d[i+a] = max(d[i+a],d[i]+b);
        d[i+1]=max(d[i+1],d[i]);
    }
    cout << d[n] << '\n';
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
long long d[101];
int n;
int main(){
    cin >> n;
    if(n <=6){
        cout << n <<endl;
    } else {
        for(int i=1;i<=6;i++){
        d[i]=i;
        }
        for(int i=7;i<=n;i++){
            d[i] = d[i-3]*2;
            d[i] = max(d[i],d[i-4]*3);
            d[i] = max(d[i],d[i-5]*4);
        }
        cout << d[n] << endl;
    }
    
    return 0;
}
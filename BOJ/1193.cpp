#include <iostream>
using namespace std;
int main(){
    int n, idx=0,sum=0;
    cin >> n;
    for(int i =1;sum+i<n;i++){
        idx++;
        sum+=i;
    }
    idx++;
    n-=sum;
    if(idx % 2 ==0) cout << n <<"/"<< idx-n+1 <<'\n';
    else cout << idx-n+1 <<"/"<< n <<'\n';
    return 0;
}
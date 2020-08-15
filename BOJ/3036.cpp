#include <iostream>
using namespace std;
int make_gcd(int a, int b){
    if (b == 0) return a;
    return make_gcd(b, a%b);
}
int main(){
    int n,k,num;
    cin >> n >> k ;
    for(int i=1;i<n;i++){
        cin >> num;
        int gcd;
        if (k > num){
            gcd = make_gcd(k,num);
        }else gcd = make_gcd(num,k);
        cout << k/gcd << '/'<< num/gcd << '\n';
    }
    return 0;
}
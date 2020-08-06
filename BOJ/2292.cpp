#include <iostream>
using namespace std;
int main(){
    long long n;
    cin >> n;
    int cnt = 1;
    long long range =  1, tmp = 1;
    while (true){
        if (range >= n){
            break;
        }
        tmp = 6 * (cnt++);
        range+=tmp;
    }
    cout << cnt;
    return 0;
}
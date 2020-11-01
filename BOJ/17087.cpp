#include <iostream>
#include <vector>
using namespace std;
int GCD(int a, int b){
    if (b == 0){
        return a;
    }
    return GCD(b, a % b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, S;
    cin >> N >> S;
    vector<int> sister_gap(N);
    for (int i = 0; i < N; i++){
        cin >> sister_gap[i];
        sister_gap[i] = (S - sister_gap[i] > 0) ? S - sister_gap[i] : sister_gap[i] - S;
    }
    int gcd = sister_gap[0];
    for (int i = 1; i < N; i++){
        gcd = GCD(gcd, sister_gap[i]);
    }
    cout << gcd;
    return 0;
}
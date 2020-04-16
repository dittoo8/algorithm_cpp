#include <iostream>
using namespace std;
int solution(int n){
    int ans = 0;
    while(n >0){
        ans += n%2;
        n /=2;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solution(5000) <<endl;
    return 0;
}
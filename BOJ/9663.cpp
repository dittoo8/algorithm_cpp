#include <iostream>
using namespace std;
bool ck1[16], ck2[31], ck3[32];
// ck1 : 세로줄 체크, ck2 : /방향 대각선, ck3: \방향 대각선
int n;
int ans;
void backtrack(int x){
    if (x ==n) {
        // 퀸을 입력받은 갯수만큼 놓았을때
        ans++;
        return;
    }
    for(int j=0;j<n;j++){
        if(ck1[j] || ck2[x+j]|| ck3[x-j+n-1]) continue;
        ck1[j] = ck2[x+j] = ck3[x-j+n-1] = true;
        backtrack(x+1);
        ck1[j] = ck2[x+j] = ck3[x-j+n-1] = false;
    }

}
int main(){
    cin >> n;
    backtrack(0);
    //0번째 줄부터 퀸을 놓는다
    cout << ans << endl;
    return 0;
}
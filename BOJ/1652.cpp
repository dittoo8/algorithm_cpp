#include <iostream>
#include <string>
#define MAX 101
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,cnt1 = 0, cnt2 = 0;
    string str[MAX];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> str[i];
    }
    int tmp1 = 0 , tmp2 = 0;
    for(int i=0;i<N;i++){
        tmp1 = 0 , tmp2 = 0;
        for(int j=0;j<N;j++){
            if(str[i][j] =='.') {
                tmp1++;
            }else {
                if(tmp1 > 1) cnt1++;
                tmp1 = 0;
            }
            if(str[j][i] =='.') {
                tmp2++;
            }else {
                if(tmp2 > 1) cnt2++;
                tmp2 = 0;
            }
        }
        if(tmp1 > 1) cnt1++;
        if(tmp2 > 1) cnt2++;
    }
    cout << cnt1 <<' '<< cnt2 << '\n';
    return 0;
}
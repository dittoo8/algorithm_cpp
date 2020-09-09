#include <iostream>
#define MAX 100001
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a[MAX];
    int n;
    cin >> n;
    if (n <=2){
        cout << 0 << '\n';
        return 0;
    }
    int answer = 987654321;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int d1 = -1;d1<=1;d1++){
        for(int d2 = -1;d2<=1;d2++){
            int change = 0;
            if (d1!=0) change++;
            if (d2!=0) change++;
            int a0 = a[0]+d1;
            int diff = (a[1]+d2) - a0;
            bool pass =true;
            int an = a0+diff;
            for(int i=2;i<n;i++){
                an+=diff;
                if(a[i]==an) continue;
                if (a[i]-1 == an || a[i]+1 == an) {
                    change++;
                }else {
                    pass = false;
                    break;
                }
            }
            if(pass){
                if (answer > change) answer =change;
            }
        }
    }
    if(answer == 987654321){
        cout << -1 << '\n';
    }else cout << answer << '\n';
    return 0;
}
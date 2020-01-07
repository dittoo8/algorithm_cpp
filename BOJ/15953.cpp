#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    int last[6][2] = {{1, 5000000},{2,3000000},{3,2000000},{4,500000},{5,300000},{6,100000}};
    int now[5][2] = {{1,5120000},{2,2560000},{4,1280000},{8,640000},{16,320000}};
    while(N--){
        int a, b;
        int ans = 0;
        cin>>a>>b;
        if (a!=0) {
            int tempA = 0;
            for(int i = 0; i <6; i++) {
                tempA += last[i][0];
                if (a<=tempA) {
                    ans += last[i][1];
                    break;
                }
            }
        }
        if (b!=0) {
            int tempB = 0;
            for(int j = 0; j <5; j++) {
                tempB += now[j][0];
                if (b<=tempB) {
                    ans += now[j][1];
                    break;
                }
            }

        }
        cout<<ans<<endl;
    }
    
    return 0;
}
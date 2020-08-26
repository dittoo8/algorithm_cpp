#include <iostream>
#include <algorithm>
using namespace std;
int a[101][2];
int main(){
    int h,w,n,answer = 0;
    cin >> h >> w >> n;
    for(int i=0;i<n;i++){
        cin >> a[i][0] >> a[i][1];
    }
    int r1,c1,r2,c2;
    for(int i=0;i<n-1;i++){ //1번 스티커
        r1 = a[i][0], c1 = a[i][1];
        for(int j=i+1;j<n;j++){ //2번 스티커
            r2 = a[j][0], c2 = a[j][1];
            for(int ro1=0;ro1<2;ro1++){ //1번 스티커 회전
                for(int ro2=0;ro2<2;ro2++){ //2번 스티커 회전 
                    if(max(r1,r2)<=h && c1+c2 <= w){
                        answer =max(answer,r1*c1+r2*c2);
                    }else if (max(c1,c2)<=w && r1+r2 <= h){
                        answer =max(answer,r1*c1+r2*c2);
                    }
                    swap(r2,c2);
                }
                swap(r1,c1);
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
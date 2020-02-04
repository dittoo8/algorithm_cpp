#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
int n;
int a[MAX];
int main(){
    a[1] = 1;
    //에라토스테네스의 체
    for(int i=2;i<MAX;i++){
        for(int j=i*2;j<MAX;j+=i){
            if(a[j]==1) continue;
            else a[j] = 1;
            //소수가 아닌 수 idx를 1로 바꿔놓음 
        }
    }
    int cnt = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
         if (a[x]==0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
#include <iostream>
using namespace std;
int a[1002];
int dP[1002];
int dM[1002];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        dP[i] = 1;
        for(int j=0;j<i;j++){
            if(a[j] < a[i] && dP[j]+1 > dP[i]){
                dP[i] = dP[j]+1;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        dM[i] = 1;
        for(int j=n-1;j>i;j--){
            if(a[j] < a[i] && dM[j]+1 > dM[i]) {
                dM[i] = dM[j] + 1;
            }
        }
    }
    int temp = 0;
    for(int i=0;i<n;i++){
        
        temp = max(temp, dP[i] + dM[i]-1);
    }
    cout << temp <<endl;
    return 0;
}
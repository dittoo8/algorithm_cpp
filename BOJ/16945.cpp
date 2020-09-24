#include <iostream>
#include <algorithm>
#define n 3
using namespace std;
int a[n*n],b[n*n];
bool is_magic(){
    int magic = b[0*n+0] + b[0*n+1] + b[0*n+2];
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum+=b[i*n+j];
        }
        if(magic != sum) return false;
    }
    for(int j=0;j<n;j++){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=b[i*n+j];
        }
        if(magic != sum) return false;
    }
    if(magic != b[0*n+0] +b[1*n+1]+b[2*n+2]) return false;
    if(magic != b[0*n+2] +b[1*n+1]+b[2*n+0]) return false;
    return true;
}
int diff(){
    int ans = 0;
    for(int i=0;i<n*n;i++){
        int temp = a[i]-b[i];
        if (temp < 0) temp = -temp;
        ans+=temp;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i=0;i<n*n;i++){
        cin >> a[i];
        b[i]=i+1;
    }
    int ans = -1;
    do {
        if(is_magic()){
            int cost = diff();
            if( ans == -1 || ans > cost){
                ans = cost;
            }
        }
    }while (next_permutation(b,b+n*n));
    cout << ans << '\n';
    return 0;
}
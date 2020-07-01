#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string a[51];
int check(){
    int ans = 1;
    for(int i=0;i<n;i++){
        int cnt = 1;
        for(int j=1;j<n;j++){
            if(a[i][j]==a[i][j-1]) cnt++;
            else cnt = 1;
            if (ans < cnt) ans = cnt;
        }
        cnt = 1;
        for(int j=1;j<n;j++){
            if(a[j][i]==a[j-1][i]) cnt++;
            else cnt = 1;
            if (ans < cnt) ans = cnt;
        }
    }
    return ans;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (j+1 < n ){
                swap(a[i][j], a[i][j+1]);
                int temp = check();
                if (ans < temp) ans = temp;
                swap(a[i][j], a[i][j+1]);
            }
            if (i+1 < n ){
                swap(a[i][j],a[i+1][j]);
                int temp = check();
                if  (ans < temp) ans = temp;
                swap(a[i][j],a[i+1][j]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
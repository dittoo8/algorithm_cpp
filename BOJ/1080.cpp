#include <iostream>
#include <string>
#define MAX 51
using namespace std;
string a[MAX], b[MAX];
int n,m;
void change(int x, int y){
    for(int i= x-1;i<=x+1; i++){
        for(int j= y-1;j<=y+1;j++){
            if(a[i][j]=='1'){
                a[i][j] = '0';
            }else a[i][j] = '1';
        }
    }
}
bool check(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    int cnt = 0;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(a[i-1][j-1] != b[i-1][j-1]){
                change(i,j);
                cnt++;
            }
        }
    }
    if(check()){
        cout << cnt << '\n';
    }else cout << -1 << '\n';
    return 0;
}
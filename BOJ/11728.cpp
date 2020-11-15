#include <iostream>
#define MAX 1000001
using namespace std;
int a[MAX], b[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    int i=0, j=0;
    while(i<n && j <m){
        if(a[i] < b[j]){
            cout << a[i] << ' ';
            i++;
        }else {
            cout << b[j] << ' ';
            j++;
        }
    }
    if(i >= n){
        for(int t = j;t<m;t++){
            cout << b[t] << ' ';
        }
    }
    if(j>=m){
        for(int t=i;t<n;t++){
            cout << a[t] << ' ';
        }
    }
    return 0;
}
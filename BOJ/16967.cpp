#include <iostream>
using namespace std;
int b[601][601];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    for(int i=0;i<h+x;i++){
        for(int j=0;j<w+y;j++){
            cin >> b[i][j];
        }
    }
    for(int i=x;i<h;i++){
        for(int j=y;j<w;j++){
            b[i][j]-=b[i-x][j-y];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << b[i][j] <<" ";
        }
        cout << '\n';
    }
    return 0;
}
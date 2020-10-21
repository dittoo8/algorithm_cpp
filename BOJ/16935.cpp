#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 101
using namespace std;
int n,m,r,a[MAX][MAX],b[MAX][MAX];
void left_switch(){
    int N = n/2;
    int M = m/2;
    int bnx[] = {N,0,N,0};
    int bny[] = {M,M,0,0};
    int anx[] = {N,N,0,0};
    int any[] = {0,M,0,M};
    for(int k=0;k<4;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                b[i+bnx[k]][j+bny[k]] = a[i+anx[k]][j+any[k]];
            }
        }
    }
    memcpy(a,b,sizeof(b));
}
void right_switch(){
    int N = n/2;
    int M = m/2;
    int bnx[] = {0,N,N,0};
    int bny[] = {M,M,0,0};
    int anx[] = {0,0,N,N};
    int any[] = {0,M,M,0};
    for(int k=0;k<4;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                b[i+bnx[k]][j+bny[k]] = a[i+anx[k]][j+any[k]];
            }
        }
    }
    memcpy(a,b,sizeof(b));
}
void left_rotate(){
    swap(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b[i][j] = a[j][n-1-i];
        }
    }
    memcpy(a,b,sizeof(b));
}
void right_rotate(){
    swap(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b[i][j] = a[m-1-j][i];
        }
    }
    memcpy(a,b,sizeof(b));
}
void left_right_mirr(){
    for(int i=0;i<m/2;i++){
        int tmp;
        for(int j=0;j<n;j++){
            tmp = a[j][i];
            a[j][i] = a[j][m-i-1];
            a[j][m-i-1] = tmp;
        }
    }
}
void up_down_mirr(){
    for(int i=0;i<n/2;i++){
        int tmp;
        for(int j=0;j<m;j++){
            tmp = a[i][j];
            a[i][j] = a[n-i-1][j];
            a[n-i-1][j] = tmp;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    int op;
    for(int i=0;i<r;i++){
        cin >> op;
        if (op == 1){
            up_down_mirr();
        }else if(op == 2){
            left_right_mirr();
        }else if(op == 3){
            right_rotate();
        }else if(op == 4){
            left_rotate();
        }else if (op == 5){
            right_switch();
        }else if (op == 6){
            left_switch();
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j] <<' ';
        }
        cout << '\n';
    }
    return 0;
}
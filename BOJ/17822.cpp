#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int a[51][51];
int b[51][51];
int n,m,t;
void rotate(int x, int d, int k){
    for(int i=1;i<=n;i++){
        if (i%x) continue;
        if (d==0){ //시계
            for(int K=0;K<k;K++){
                int tmp = a[i][m];
                for(int j=m;j>=2;j--){
                    a[i][j] = a[i][j-1];
                }
                a[i][1] = tmp;
            } 
        }else { //반시계
            for(int K=0;K<k;K++){
                int tmp = a[i][1];
                for(int j=1;j<m;j++){
                    a[i][j] = a[i][j+1];
                }
                a[i][m] = tmp;
            }
        }
    }
    memcpy(b,a,sizeof(a));
    bool ck = false;
    int sum = 0;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==0) continue;
            if(a[i][j]>0) cnt++;
            sum+=a[i][j];
            if(a[i][j]==a[i+1][j]){
                b[i][j] = 0;
                b[i+1][j]=0;
                ck = true;
            }
            if(a[i][j]==a[i-1][j]){
                b[i][j] = 0;
                b[i-1][j]=0;
                ck = true;
            }
            if(j==1){
                if(a[i][j]==a[i][m]){
                    b[i][j] = 0;
                    b[i][m] = 0;
                    ck = true;
                }
            }else {
                if(a[i][j]==a[i][j-1]){
                    b[i][j] =0;
                    b[i][j-1] =0;
                    ck = true;
                }
            }
        }
    }
    memcpy(a,b,sizeof(a));
    double mid = double(sum)/double(cnt);
    if(ck==false){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==0)continue;
                if(a[i][j]>mid) {
                    a[i][j]--;
                }else if(a[i][j]<mid) {
                    a[i][j]++;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    int x, d, k;
    for(int i=0;i<t;i++){
        cin >> x >>d >> k;
        rotate(x,d,k);
    }
    int sum =0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum+=a[i][j];
        }
    }
    cout << sum << '\n';
    return 0;
}
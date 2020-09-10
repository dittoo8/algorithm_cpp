#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,k;
int a[51][51],b[51][51];
int rot[6][3];
int lis[6];
void rotate_mat(int idx){
    int x = rot[idx][0];
    int y = rot[idx][1];
    int s = rot[idx][2];
    while (s > 0) {
        int tmp = b[x - s][y - s];
        for (int i = x - s; i < x + s; i++) {
            b[i][y - s] = b[i + 1][y - s];
        }
        //마지막 행 이동
        for (int j = y - s; j < y + s; j++) {
            b[x + s][j] = b[x + s][j + 1];
        }
        //마지막 열 이동
        for (int i = x + s; i > x - s; i--) {
            b[i][y + s] = b[i - 1][y + s];
        }
        //첫번째 행 이동
        for (int j = y + s; j > y - s + 1; j--) {
            b[x - s][j] = b[x - s][j - 1];
        }
        //마지막 칸
        b[x - s][y - s + 1] = tmp;
        s--;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int ans = 100000;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<k;i++){
        cin >> rot[i][0] >> rot[i][1] >> rot[i][2];
        rot[i][0]--;
        rot[i][1]--;
        lis[i] = i;
    }
    do {
        memcpy(b,a,sizeof(a));
        for(int i=0;i<k;i++){
            rotate_mat(lis[i]);
        }
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<m;j++){
                sum+=b[i][j];
            }
            if (ans > sum) ans = sum;
        }
    } while (next_permutation(lis,lis+k));

    cout << ans << '\n';
    return 0;
}
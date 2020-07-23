#include<iostream>
using namespace std;

int n, h[51][2];
int main(void){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i][0] >> h[i][1];
 
    for (int i = 0; i < n; i++){
        int cnt = 1;
        for (int j = 0; j < n; j++){
            if (h[i][0] < h[j][0] && h[i][1] < h[j][1])
                cnt++;
        }
        cout << cnt << " ";
    }
    return 0;
}
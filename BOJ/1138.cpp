#include <iostream>
using namespace std;
int line[11];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(cnt == x && line[j]==0){
                line[j] = i;
                break;
            }
            if(line[j]==0) cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        cout << line[i] << " ";
    }
    return 0;
}
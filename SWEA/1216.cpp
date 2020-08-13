#include <iostream>
#include <string>
#define MAX 100
using namespace std;
string map[MAX];
int check(int x, int y){
    for(int k=MAX;k>=2;k--){
        int width = k,height = k;
        for(int t = 0;t<=k/2;t++){
            if((y+k-1)< MAX) {
                if(map[x][y+t]!= map[x][k-t+y-1]) width = 1;
            }else width = 1;
            if ((x+k-1)<MAX){
                if (map[x+t][y]!= map[k-t+x-1][y]) height = 1;
            }else height = 1;
        }
        if (width > 1) return width;
        if (height > 1) return height;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    for(int test_case = 1; test_case<=10;test_case++){
        cin >> tc;
        int ans = 1;
        for(int i=0;i<MAX;i++){
            cin >> map[i];
        }
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                int cnt = check(i,j);
                if (cnt > ans) ans = cnt;
            }
        }
        cout <<"#" <<test_case <<" " << ans <<endl;
    }
    return 0;
}
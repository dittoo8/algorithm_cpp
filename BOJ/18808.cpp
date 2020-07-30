#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,m,k;
int sticker[12][12];
int r,c;
int map[41][41];
void rotate(){
    int tmp[12][12];
    memcpy(tmp,sticker,sizeof(tmp));
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            sticker[i][j]=tmp[r-1-j][i];
        }
    }
    swap(r,c);
}
bool stick(int x, int y){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if (map[x+i][y+j] && sticker[i][j]) {
                return false;
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            map[x+i][y+j]+=sticker[i][j];
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);
    cin >> n >> m >> k ;
    while(k--){
        cin >> r >> c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c ;j++){
                cin >> sticker[i][j];
            }
        }
        for(int rot = 0; rot < 4; rot++){
            bool is_paste = false;
            for(int x= 0 ; x<=n-r;x++){
                if (is_paste) break;
                for(int y = 0; y<=m-c;y++){
                    if (stick(x,y)){
                        is_paste = true;
                        break;
                    }
                }
            }
            if (is_paste) break;
            rotate();
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cnt+=map[i][j];
        }
    }
    cout << cnt << '\n';
    return 0;
}
#include <cstdio>
#include <cmath>
using namespace std;
int n,r,c;
int cnt;
void solve(int size, int y, int x){
    if(size == 2) {
        if(y==r && x == c) {
            printf("%d",cnt);
            return;
        }
        cnt++;
        if(y==r && x+1 == c) {
            printf("%d",cnt);
            return;
        }
        cnt++;
        if(y+1 ==r && x == c) {
            printf("%d",cnt);
            return;
        }
        cnt++;
        if(y+1 ==r && x+1 == c) {
            printf("%d",cnt);
            return;
        }
        cnt++;
        return;
        
    } else {
        solve(size/2, y, x);
        solve(size/2, y, x + size/2);
        solve(size/2, y+size/2,x);
        solve(size/2,y+size/2,x+size/2);
    }
}
int main(){
    scanf("%d %d %d", &n, &r, &c);
    solve(pow(2,n),0,0);
}
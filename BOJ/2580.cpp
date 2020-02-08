#include <iostream>
#include <vector>
using namespace std;
int map[10][10];
bool RowUsed[9][10], ColUsed[9][10], SqrUsed[9][10];
void backtrack(){
    int x = -1, y = -1;
    for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(map[i][j]==0){
                    x = i;
                    y = j;
                    break;
                }
            }
            if(x != -1) break;
        }
    if(x == -1) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    int s = 3*(x/3) + (y/3);
    for (int i=1; i<=9; i++) {
        bool &rUsed = RowUsed[x][i];
        bool &cUsed = ColUsed[y][i];
        bool &sUsed = SqrUsed[s][i];
        if (!rUsed && !cUsed && !sUsed) {
            rUsed = cUsed = sUsed = true;
            map[x][y] = i;
            backtrack();
            map[x][y] = 0;
            rUsed = cUsed = sUsed = false;
        }
    }
}
int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int a;
            scanf("%1d", &a);
            map[i][j] = a;
            RowUsed[i][a] = true;
            ColUsed[j][a] = true;
            SqrUsed[3*(i/3)+(j/3)][a] = true;
        }
    }
    backtrack();
    
    return 0;
}
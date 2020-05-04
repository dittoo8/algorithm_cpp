#include <cstdio>
#include <algorithm>
using namespace std;
int main(void){
    for (int z = 1; z <= 10; z++) {
        int cnt = 0;
        int n;
        scanf("%d\n", &n);
        char map[10][10] = { {0,}, };
        for(int i=0;i<8;i++)
            scanf("%s", map[i]);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                int check1 = 0;
                int check2 = 0;
                for (int k = 0; k <= n / 2; k++) {
                    if ((j + n - 1) < 8) {
                        if (map[i][j+k] != map[i][n - k+j-1]) check1 = 1;
                    }else check1 = 1;
                    if (((i + n - 1) < 8)) {
                        if (map[i + k][j] != map[n - k +i- 1][j]) check2 = 1;
                    }else check2 = 1;
                }
                if (check1 == 0) cnt++;
                if (check2 == 0) cnt++;
            }
        }
        printf("#%d %d\n", z, cnt);
    }
    return 0;
}
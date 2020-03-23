#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 6;
int k;
int lotto[MAX];
int arr[13];
void printLotto(int idx1, int idx2){
    if (idx2 == MAX){
        for (int i = 0; i < MAX; i++) {
            printf("%d ", lotto[i]);
        }
        printf("\n");
        return;
    }
    for (int i = idx1; i < k; i++){
        lotto[idx2] = arr[i];
        printLotto(i + 1, idx2 + 1);
    }
}
int main(void){
    while (1){
        scanf("%d", &k);
        if (k == 0) break;
        for (int i = 0; i < k; i++) {
            scanf("%d", &arr[i]);
        }
        printLotto(0, 0);
        printf("\n");
    }
    return 0;
}
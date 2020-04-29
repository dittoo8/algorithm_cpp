#include <cstdio>
using namespace std;
int n;
int a[21];
bool ck[20*100000];
void backtrack(int idx, int sum){
    if (idx == n){
        ck[sum]= true;
        return;
    }
    backtrack(idx+1, sum+a[idx]);
    backtrack(idx+1, sum);
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    backtrack(0,0);
    int start =1;
    while(true){
        if(!ck[start]){
            printf("%d\n", start);
            return 0;
        }
        start++;
    }
    return 0;
}
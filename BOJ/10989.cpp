#include <cstdio>
using namespace std;
int nums[10002];
int n;
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d", &a);
        nums[a]++;
    }
    for(int i=1;i<=10001;i++){
        while(nums[i]>0){
            printf("%d\n",i);
            nums[i]--;
        }
    }
    return 0;
}
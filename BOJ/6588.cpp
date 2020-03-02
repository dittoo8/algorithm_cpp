#include <cstdio>
#define MAX 1000001
using namespace std;
bool a[MAX];
int main(){
    a[1]=true;
    for(int i=2;i<MAX;i++){
        if(i%2==0) a[i]=true;
        if(a[i]) continue;
        for( int j=i+i;j<MAX;j+=i){
            a[j]=true;
        }
    }
    while(1){
        int n;
        scanf("%d", &n);
        if (n==0) break;
        int i=3;
        bool check = false;
        while(1){
            if (!a[i]&&!a[n-i]) {
                check = true;
                printf("%d = %d + %d\n",n,i,n-i);
                break;
            }
            for(int k=i+1;k<n/2;k++){
                if(!a[k]) {
                    i=k;
                    break;
                }
            }
        }
        if(!check){
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
    return 0;
}
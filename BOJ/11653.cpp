#include<cstdio>
int main(){
    int n; scanf("%d", &n);
    for(int i = 2 ; i < 10000000 || n != 1 ; i++){
        while(n%i==0){
            printf("%d\n",i);
            n/=i;            
        }
    }
    return 0;
}
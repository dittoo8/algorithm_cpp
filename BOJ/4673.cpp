#include <cstdio>
#define MAX  10001
using namespace std;
int a[MAX];
int d[MAX];
int getNext(int x){
    int sum = x, tmp = x,cipher = 1;
    while(tmp >=10){
        cipher++;
        tmp /= 10;
    }
    for(int i=0;i<cipher;i++){
        sum+= x%10;
        x/=10;
    }
    return sum;
}
int main(){
    for(int i=1;i<MAX;i++){
        for(int j=getNext(i);j<MAX;j = getNext(j)){
            if(a[j]==1) continue;
            else a[j]=1;
        }
    }
    for(int i=1;i<MAX;i++){
        if(a[i]==0) {
            printf("%d\n",i);
        }
    }

    return 0;
}
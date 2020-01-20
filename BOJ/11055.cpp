#include <cstdio>
using namespace std;
int n;
int a[1002];
int d[1002];
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    d[1]= a[1];
    int max = 0;
    for(int i=1;i<=n;i++){
        int tmp =0;
        for(int j=1;j<i;j++){
            if(a[j]<a[i]) {
                if(d[j] > tmp) tmp = d[j];
            } 
        }
        d[i] = tmp +a[i];
        if (d[i] > max) max =d[i];
        
    }
    printf("%d", max);
    return 0;
}
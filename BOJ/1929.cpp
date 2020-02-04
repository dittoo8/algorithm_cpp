#include <cstdio>
#define MAX 1000001
using namespace std;
bool a[MAX];
int main(){
    a[1]= 1;
    //에라토스테네스의 체
    for(int i=2;i<=MAX;i++){
        for(int j=i*2;j<=MAX;j+=i){
            if(a[j]==true) continue;
            else a[j]=true;
        }
    }
    int m,n;
    scanf("%d %d", &m, &n);
    for(int i =m;i<=n;i++){
        if(a[i]==false) printf("%d\n", i);
    }
    return 0;
}
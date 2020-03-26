#include <cstdio>
using namespace std;
int e,s,m,y;
int main(){
    scanf("%d %d %d", &e, &s, &m);
    while(++y){
        if(!((y-e)%15 || (y-s)%28 || (y-m)%19))break;
    }
    printf("%d\n",y);
    return 0;
}
#include <cstdio>
int building[15][15];
int main(){
    for(int i=0;i<15;i++){
        building[i][1]=1;
    }
    for(int j=0;j<15;j++){
        building[0][j]=j;
    }
    for(int i=1;i<15;i++){
        for(int j=2;j<15;j++){
            building[i][j] = building[i-1][j]+building[i][j-1];
        }
    }
    int tc,k,n;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d",&k, &n);
        printf("%d\n",building[k][n]);
    }
    return 0;
}
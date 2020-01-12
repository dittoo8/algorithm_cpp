/*
N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1의 세 값 중 하나가 저장되어 있다. 우리는 이 행렬을 적절한 크기로 자르려고 하는데, 이때 다음의 규칙에 따라 자르려고 한다.

만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
(1)이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.
*/
#include <cstdio>
using namespace std;
int arr[2200][2200];
int res[3] = {0,};
bool same(int x, int y, int len){
    for(int i=y;i<y+len;i++){
        for(int j=x;j<x+len;j++){
            if (arr[y][x]!= arr[i][j])
               return false;
        }
    }
    return true;
}
void solve(int x, int y, int len){
    if(same(x,y,len)) {
        //0,0~x,y 가 모두 같다면
        if (arr[y][x]==-1) res[0]++;
        if (arr[y][x]==0) res[1]++;
        if (arr[y][x]==1) res[2]++;

        return;
    }
    int m = len/3;
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            solve(x+j*m,y+i*m,m);
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    solve(0,0,n);
    
    printf("%d\n%d\n%d", res[0], res[1], res[2]);

}
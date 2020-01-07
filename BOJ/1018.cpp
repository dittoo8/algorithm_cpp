/*
지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다.어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8*8 크기의 체스판으로 만들려고 한다.

체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.

보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8*8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;
string chess1[8];
string chess2[8];
// 두 가지 경우의 8x8체스판 만들기
void makeChess(){
    string tempChess1 = "BWBWBWBW";
    string tempChess2 = "WBWBWBWB";

    for(int i=0;i<8;i++){
        if (i%2 == 0){
            chess1[i] = tempChess1;
            chess2[i] = tempChess2;
        } else {
            chess1[i] = tempChess2;
            chess2[i] = tempChess1;
        }
    }
}
int eightCheck(string inputChess[],int a, int b){
    int cnt1 = 0;
    int cnt2 = 0;
    int minTemp = 64;
    //chess1 Check
    int ci1 = 0;
    for(int i=a;i<a+8;i++){
        int cj = 0;
        for(int j=b;j<b+8;j++){
            if(inputChess[i][j] != chess1[ci1][cj]){
                cnt1++;
            }
            cj++;
        }
        ci1++;
        minTemp = min(minTemp,cnt1);
    }
    //chess2 Check
    int ci2 = 0;
    for(int i=a;i<a+8;i++){
        int cj = 0;
        for(int j=b;j<b+8;j++){
            if(inputChess[i][j] != chess2[ci2][cj]){
                cnt2++;
            }
            cj++;
        }
        ci2++;
        minTemp = min(cnt1,cnt2);

    }
    return minTemp;
}
int checkChess(string inputChess[],int a, int b){
    int minChess = 64;
    for(int i=0;i<=a-7;i++){
        for(int j=0;j<=b-7;j++){
            minChess = min(minChess, eightCheck(inputChess, i, j));
            }
    }
    return minChess;
}

int main(){
    makeChess();
    int a, b;
    cin>>a>>b;
    string inputChess[a];
    for(int i=0;i<a;i++){
        cin>>inputChess[i];
    }
    cout<<checkChess(inputChess, a, b)<<endl;

    return 0;
}
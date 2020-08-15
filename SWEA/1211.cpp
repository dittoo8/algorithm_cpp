
#include<iostream>
#define MAX 1000
using namespace std;
int arr[101][101],cnt=0;
int min_x = 0, min_cnt = MAX;
int main() {//사다리타기
    for (int t = 1; t <= 10; t++) {
        int num;
        cin >> num;
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                cin >> arr[i][j];
        for (int i = 0; i < 100; i++){
            if (arr[0][i]) {
                int x = 0,y = i;
                while (x < 99) {
                    x++; cnt++;
                    if (arr[x][y + 1]) {
                        do {
                            y++; cnt++;
                        } while (arr[x][y + 1]);
                    }else if (arr[x][y - 1]) {
                        do {
                            y--; cnt++;
                        } while (arr[x][y - 1]);
                    }
                    if (cnt > min_cnt) break;
                }
                if (min_cnt >= cnt) { 
                    min_cnt = cnt, min_x = i;
                }
                cnt = 0;
            }
        }
        cout << "#" << t << ' ' << min_x << endl;
        min_cnt = MAX, min_x = 0;
    }
    return 0;
}
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 3; i++) {
        int s = 0, a;
        for (int j = 0; j < 4; j++) cin >> a, s += a;
        switch (s) {
            case 0: puts("D"); break;
            case 1: puts("C"); break;
            case 2: puts("B"); break;
            case 3: puts("A"); break;
            case 4: puts("E");
        }
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for (int j = 0; j < N; j++){
        string A, B;
        cin >> A >> B;
        cout << "Distances: ";
        for (int i = 0; i < A.length(); i++){
            int y = B[i] - '0';
            int x = A[i] - '0';
            if (y - x >= 0) {
                cout << y - x << " ";
            } else {
                cout << y - x + 26 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
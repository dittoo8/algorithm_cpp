#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    char input[101];
    while (fgets(input, 101, stdin)){
        cout << input;
    }
    return 0;
}

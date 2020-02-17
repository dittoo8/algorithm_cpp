#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

int solution(int n) {
    int num = bitset<20>(n).count();
    int i = n+1;
    while(bitset<20>(i).count()!=num){
        i++;
    }
    return i;
}
int main(){
    cout << solution(78) << endl;
    return 0;
}
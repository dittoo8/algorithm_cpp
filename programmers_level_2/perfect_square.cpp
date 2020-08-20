#include <iostream>
using namespace std;
int make_gcd(int a, int b){
    if (b == 0) return a;
    return make_gcd(b, a%b);
}
long long solution(int w,int h) {
    int gcd;
    if (w > h){
        gcd = make_gcd(w,h);
    }else {
        gcd = make_gcd(h,w);
    }
    long long answer = (long long)w*h - (w+h-gcd);
    return answer;
}
int main(){
    cout << solution(8, 12) <<endl;
    return 0;
}
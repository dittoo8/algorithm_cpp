#include <iostream>
using namespace std;
int solution(int n, int a, int b){
    int answer = 0;
    while(true){
        answer++;
        if (((a-b==1) && b%2 )|| ((b-a==1) && a%2)) break;
        a = a%2 +a/2;
        b = b%2 +b/2;
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solution(8,4,7) << endl;
    return 0;
}
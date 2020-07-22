#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
int  N,ans,row[13];
bool promising(int i){
    for(int j=0;j<i;j++){
        if(row[i]==row[j] ||abs(row[i]-row[j])== (i-j)){
            return false;
        }
    }
    return true;
}
void n_queen(int i){
    if (i == N){
        ans++;
        return;
    }
    for(int j=0;j<N;j++){
        row[i]=j;
        if(!promising(i)) continue;
        n_queen(i+1);
    }
}
int solution(int n) {
    int answer;
    N = n;
    n_queen(0);
    answer = ans;
    return answer;
}
int main(){
    cout << solution(4) << endl;
    return 0;
}
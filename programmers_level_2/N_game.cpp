#include <iostream>
#include <string>
#include <vector>
using namespace std;
char c[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string dec2N(int num,int n){
    string res = "";
    while(num/n!=0){
        res=c[num%n]+res;
        num/=n;
    }
    res=c[num%n]+res;
    return res;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "";
    for(int i=0;i<m*t;i++){
        tmp+=dec2N(i,n);
    }
    int cnt =0;
    for(int i=p-1;i<tmp.length() && cnt < t;i+=m){
        answer+=tmp[i];
        cnt++;
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << solution(16,16,2,1) << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MAX 1e6+1
#define INF 987654321
using namespace std;
int n,m,ans;
bool check[10];
bool possible(int num){
    if (num==0){
        if (!check[0]) return true;
        else return false;
    }
    while(num){
        if (check[num%10]) return false;
        num/=10;
    }
    return true;
}
int length(int num){
    if (num == 0)return 1;
    int res = 0;
    while(num){
        num/=10;
        res++;
    }
    return res;
}
int move(){
    int res = INF;
    int near = 0;
    for(int i=0;i<MAX;i++){
        if(possible(i)){
            int press = abs(n-i);
            if (res > press){
                res = press;
                near =i;
            }
        }
    }
    return res + length(near);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        int temp;
        cin >> temp;
        check[temp] = true;
    }
    ans = abs(n-100);
    cout << min(ans, move()) <<endl;

    return 0;
}
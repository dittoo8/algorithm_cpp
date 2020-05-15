#include <iostream>
#include <cstring>
using namespace std;
long long cache[31][31];
long long solve(int one, int half){
    if (one==0) return 1;
    long long &ret = cache[one][half];
    if (ret!=-1){
        return ret;
    }
    ret=0;
    ret = solve(one-1,half+1);
    if(half>0) ret+= solve(one,half-1);
    return ret;
}
int main(){
    while(true){
        memset(cache,-1,sizeof(cache));
        int n;
        cin >> n ;
        if(n==0) break;
        cout << solve(n,0) <<endl;
    }
    return 0;
}
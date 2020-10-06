#include <iostream>
using namespace std;
int d[46];
int f(int x){
    if (d[x]!=-1) return d[x];
    int ret =0;
    if(d[x-1]!=-1) ret+=d[x-1];
    else ret+=f(x-1);
    if(d[x-2]!=-1) ret+=d[x-2];
    else ret+=f(x-2);
    return d[x] = ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    fill(&d[0], &d[n]+1,-1);
    d[0] = 0;
    d[1] = 1;
    cout << f(n) << '\n';
    return 0;
}
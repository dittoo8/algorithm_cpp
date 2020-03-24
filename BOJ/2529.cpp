#include <cstdio>
#include <string>
using namespace std;
int n;
char op[9];
bool c[10];
string mn,mx;
bool possible(int i, int j, char k){
    if (k== '<') return i<j;
    if (k== '>') return i>j;
    return true;
}
void solve(int cnt, string s){
    if(cnt == n+1){
        if (!mn.size()) mn=s;
        else mx = s;
        return;
    }
    for(int i=0;i<10;i++){
        if (c[i]) continue;
        if(cnt==0 || possible(s[cnt-1],i+'0',op[cnt-1])){
            c[i]=true;
            solve(cnt+1, s+to_string(i));
            c[i]=false;
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%1c",&op[i]);
    }
    solve(0,"");
    for(int i=0;i<mx.length();i++){
        printf("%c",mx[i]);
    }
    printf("\n");
    for(int i=0;i<mn.length();i++){
        printf("%c",mn[i]);
    }
    return 0;
}
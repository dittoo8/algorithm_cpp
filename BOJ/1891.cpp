#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long long sx,sy;
string f_end(long long x, long long y, long long sZ, long long ex, long long ey){
    if(sZ == 1) return "";
    if (ex < x + sZ / 2 && ey < y+ sZ / 2) return "2" + f_end(x,y,sZ/2,ex,ey);
    else if(ex < x+sZ/2 && ey >= y+sZ/2) return "1" + f_end(x,y+sZ/2,sZ/2,ex,ey);
    else if(ex>=x+sZ/2 && ey< y+ sZ/2) return "3" + f_end(x+sZ/2,y,sZ/2,ex,ey);
    else return "4" + f_end(x+sZ/2,y+sZ/2,sZ/2,ex,ey);
}
void f_start(long long x, long long y, long long sZ, long long depth, string& s){
    if(sZ == 1) {
        sx = x, sy = y;
        return;
    }
    if(s[depth]=='1'){
        f_start(x,y+sZ/2,sZ/2,depth+1,s);
    }else if(s[depth]=='2'){
        f_start(x,y,sZ/2,depth+1,s);
    }else if(s[depth]=='3'){
        f_start(x+sZ/2,y,sZ/2,depth+1,s);
    }else if(s[depth]=='4'){
        f_start(x+sZ/2,y+sZ/2,sZ/2,depth+1,s);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long d,x,y,sZ,ex,ey;
    string n;
    cin >> d >> n >> x >> y;
    sZ = pow(2,(int)n.length());
    f_start(0,0,sZ,0,n);
    ex = sx-y, ey = sy+x;
    if (ex < 0 || ex >= sZ || ey < 0 || ey >= sZ){
        cout << -1 << '\n';
    }else {
        cout << f_end(0,0,sZ,ex,ey) << '\n';
    }
    return 0;
}
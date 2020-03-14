#include <cstdio>
#include <cstdlib>
using  namespace std;
int n,a[20][20],res=1000000;
bool ck[20];
void solve(int cnt,int idx){
    if(cnt==n/2){
        int tcnt=0,fcnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ck[i]== true && ck[j]==true){
                    tcnt+=a[i][j];
                }else if (ck[i]==false && ck[j]==false){
                    fcnt+=a[i][j];
                }
            }
        }
        if(res > abs(tcnt-fcnt)) res = abs(tcnt-fcnt);
        return;
    }else {
        for(int i=idx;i<n;i++){
            ck[i]=true;
            solve(cnt+1,i+1);
            ck[i]=false;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    solve(0,0);
    printf("%d", res);
    return 0;
}
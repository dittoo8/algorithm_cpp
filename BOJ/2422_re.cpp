#include <cstdio>
using namespace std;
bool ck[201][201];
int main(){
    int n,m,ans=0;
    scanf("%d %d", &n, &m);
    int ta,tb;
    for(int i=0;i<m;i++){
        scanf("%d %d", &ta, &tb);
        ck[ta][tb]=true;
        ck[tb][ta]=true;
    }
    for(int i=1;i<=n-2;i++){ //첫번째로 선택하는 아이스크림 
        for(int j=i+1;j<=n-1;j++){ //두번째로 선택하는 아이스크림
            for(int k=j+1;k<=n;k++){ //세번째로 선택하는 아이스크림
                // 같이 선택하면 안되는 조합이 포함된 경우 
                if(ck[i][j] || ck[j][k] || ck[i][k]) continue;
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
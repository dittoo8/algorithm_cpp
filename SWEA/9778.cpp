#include <cstdio>
using namespace std;
int tc,n,tsum;
int card[12];
void setCard(){
    for(int i=2;i<=9;i++){
        card[i]=4;
    }
    card[10]=16;
    card[11]=4;
}
int main(){
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++){
        tsum=0;
        int tmp;
        setCard();
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &tmp);
            card[tmp]--;
            tsum+=tmp;
        }
        int num = 21-tsum;
        int cnt1=0;
        int cnt2=0;
        for(int i=2;i<=num;i++){
            cnt1+=card[i];
        }
        for(int i= num+1;i<=11;i++){
            cnt2+=card[i];
        }
        if (cnt1 < cnt2){
            printf("#%d STOP\n",t);
        }else {
            printf("#%d GAZUA\n",t);
        }
    }
    return 0;
}
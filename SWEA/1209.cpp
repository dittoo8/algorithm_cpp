#include <iostream>
#include <algorithm>
using namespace std;
int col[100],row[100],Adddiagonal,Minusdiagonal;
int main(){
    int t,num;
    for(int tc = 1;tc<=10;tc++){
        fill(&col[0], &col[99]+1,0);
        fill(&row[0], &row[99]+1,0);
        Adddiagonal = 0; Minusdiagonal = 0;
        cin >>  t;
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                cin >> num;
                col[j]+=num;
                row[i]+=num;
                if (i==j) {
                    Adddiagonal+=num;
                }
                if (99-i == j ){
                    Minusdiagonal+=num;
                }
            }
        }
        int a = *max_element(col,col+100);
        int b = *max_element(row,row+100);
        cout << "#" <<tc <<' '<<max(max(a,b),max(Adddiagonal,Minusdiagonal)) << '\n';
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int TC,acnt,bcnt,ccnt;
    string N;
    cin>>TC;
    for (int t=1;t<=TC;t++){
        cin>>N;
        bool check = true;
        acnt=0,bcnt=0,ccnt=0;
        for(int i=0;i<N.length();i++){
            switch (N[i]){
                case 'a':
                    acnt++;
                    break;
                case 'b':
                    bcnt++;
                    break;
                case 'c':
                    ccnt++;
                    break;
            }
        }
        int temp = max(max(acnt,bcnt),ccnt)-min(min(acnt,bcnt),ccnt);
        if(temp>1)
            check = false;
        if(check)
            cout<<'#'<<t<<" YES\n";
        else
            cout<<'#'<<t<<" NO\n";
    }
    return 0;
}
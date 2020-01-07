#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long num;
    scanf("%lld", &num);

    for(int i=1;i<num;i++) {
        int numTem=0;
        int thisNum = i;

        while( thisNum!=0) {
            numTem += thisNum % 10;
            thisNum = thisNum/10;
        }
        if (i+numTem == num) {
            cout<<i<<endl;
            return 0;
        }
    } cout<<0<<endl;
}
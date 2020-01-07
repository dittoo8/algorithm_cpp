#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int nan[9];
    int nanSum = -100;

    for(int i=0;i<9;i++) {
        cin>>nan[i];
        nanSum+=nan[i];
    }
    sort(nan,nan+9);
    for(int j=0;j<9;j++){
        for(int k=j+1;k<9;k++){
                if (nanSum == nan[j]+nan[k]) {
                        for(int h=0;h<9;h++){
                            if (h!=j && h!=k) {
                           cout << nan[h] << endl;
                            }
                        }
                        return 0;
                }

        }
    }
    
    }
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string bom[51];
int N;
int horMaxTemp = 1;
int verMaxTemp = 1;
int horCheckMaxTemp = 1;
int verCheckMaxTemp = 1;

int check(){

    int cntTemp = 1;

    // horizontal Check
    for(int i=0;i<N;i++){
                            cntTemp = 1;

        for(int j=1;j<N;j++){
            // if (i != 0 && j!=0){
                // cout<<"horizontal loop : "<<i<<","<<j<<endl;
                if (bom[i][j]==bom[i][j-1]){
                    cntTemp++;
                    // cout<< "horizontal check Temp : "<<cntTemp<<endl;

                } else {
                    // cout<<"horizontal check Max : "<<horCheckMaxTemp<<endl;
                            cntTemp = 1;

                }
                horCheckMaxTemp = max(horCheckMaxTemp, cntTemp);

            // }
        }
    }
    //vertical Check
    for(int j=0;j<N;j++){
                            cntTemp = 1;

        for(int i=1;i<N;i++){
                cout<<"vertical loop : "<<i<<","<<j;
                if(bom[i][j]==bom[i-1][j]){
                    cntTemp++;
                    // cout<< "vertical check Temp i,j, temp : "<<i<<","<<j<<","<<cntTemp<<endl;
                             cout<<"  cntTemp : "<<cntTemp<<endl;

                } else {
                    // cout<< "vertical check Temp i,j, temp : "<<i<<","<<j<<","<<cntTemp<<endl;
                 cout<<"  cntTemp : "<<cntTemp<<endl;

                    // cout<<"vertical check Max : "<<verCheckMaxTemp<<endl;
                            cntTemp = 1;

                    
                }
                verCheckMaxTemp = max(verCheckMaxTemp, cntTemp);

        }
    }


    
    return max(horCheckMaxTemp,verCheckMaxTemp);
}

int horizontalMax(){
    int horTemp = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            cout<<"horizontal Swap i,j : "<<i<<","<<j<<endl;
            cout<<"horizontal Swap i,j ~ : "<< i<<","<<j+1<<endl;

            //horizontal Swap
            horTemp = bom[i][j];
            bom[i][j] = bom[i][j+1];
            bom[i][j+1] = horTemp;

            //체크
            // cout<<"horizontal Check"<<endl;

            horMaxTemp = max(horMaxTemp, check());

            //horizontal Swap
            horTemp = bom[i][j];
            bom[i][j] = bom[i][j+1];
            bom[i][j+1] = horTemp;

        }
    }

    return horMaxTemp;
}
int verticalMax(){
    int verTemp = 0;
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N;j++){
            // cout<<"vertical Swap i,j : "<<i<<","<<j<<endl;
            // cout<<"vertical Swap i,j ~ : "<<i+1<<","<<j<<endl;

            //vertical Swap
            verTemp = bom[i][j];
            bom[i][j] = bom[i+1][j];
            bom[i+1][j] = verTemp;

            //체크

            // cout<<"vertical Check"<<endl;
            verMaxTemp = max(verMaxTemp, check());

            //vertical Swap
            verTemp = bom[i][j];
            bom[i][j] = bom[i+1][j];
            bom[i+1][j] = verTemp;

        }
    }

    return verMaxTemp;
}
int main(){
    int horMax;
    int verMax;
    //배열 크기 입력받음
    cin>>N;
    for (int i=0;i<N;i++) {
        cin>>bom[i];
    }
    horMax = horizontalMax();
    
    verMax = verticalMax();
    cout<<"horMax : "<<horMax<<endl;
    cout<<"verMax : "<<verMax<<endl;

    cout<<max(horMax, verMax)<<endl;

    return 0;
}
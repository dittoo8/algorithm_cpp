#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
int n,m;
string a[MAX];
string res;
int cnt[MAX][4];
int main(){
    int count = 0 ;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(a[i][j]=='A'){
                cnt[j][0]++;
            } else if (a[i][j] == 'C'){
                cnt[j][1]++;
            } else if(a[i][j] == 'G'){
                cnt[j][2]++;
            } else if(a[i][j] == 'T'){
                cnt[j][3]++;
            } 
        }
       
    }
    for(int j=0;j<m;j++){
        int max = 0,idx;
        for(int i=0;i<4;i++){
            if (max < cnt[j][i]) {
                max = cnt[j][i];
                idx = i;
            }
        }
        if (idx ==0) res+='A';
        if (idx ==1) res+='C';
        if (idx ==2) res+='G';
        if (idx ==3) res+='T';
        count += n-max;
    }
    cout << res << endl;
    cout << count << endl;
    
    return 0;
}
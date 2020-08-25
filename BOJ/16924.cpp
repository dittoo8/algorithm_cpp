#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,m,len;
struct cross{
    int x, y,d;
};
vector<cross> v;
bool visit[101][101];
string str[101];
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> str[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (str[i][j]=='*'){
                int  l = 0;
                for(int k=1;;k++){
                    if (i+k < n && i-k >= 0 && j+k < m && j-k >= 0) {
                        if (str[i+k][j] == '*' && str[i-k][j] == '*' && str[i][j+k] == '*' && str[i][j-k] == '*') {
                            l = k;
                        } else break;
                    } else break;
                }
                if( l>0){
                    v.push_back({i+1,j+1,l});
                    visit[i][j] = true;
                    for(int k=1;k<=l;k++){
                        visit[i+k][j] = true;
                        visit[i-k][j] = true;
                        visit[i][j-k] = true;
                        visit[i][j+k] = true;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str[i][j]=='*' && !visit[i][j]) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << (int)v.size() << '\n';
    for(int i=0;i<v.size();i++){
        cout << v[i].x <<' ' << v[i].y <<' ' << v[i].d << '\n';
    }
    return 0;
}
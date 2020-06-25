#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool ck[101][101];
const int dx[] = {0,-1,0,1},dy[]={1,0,-1,0};
vector<int> curve(int x, int y ,int dir, int gen){
    vector<int> ans = {dir};
    for(int g=1;g<=gen;g++){
        vector<int> temp(ans);
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            temp[i]= (temp[i]+1)%4;
        }
        ans.insert(ans.end(),temp.begin(),temp.end());
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--){
        int x,y,dir,gen;
        cin >> y >> x >> dir>> gen;
        vector<int> dirs = curve(x,y,dir,gen);
        ck[x][y] = true;
        for(int i = 0;i<dirs.size();i++){
            x+=dx[dirs[i]];
            y+=dy[dirs[i]];
            ck[x][y]=true;
        }
    }
    int ans = 0;
    for(int i=0;i<=99;i++){
        for(int j=0;j<=99;j++){
            if (ck[i][j] && ck[i][j+1] && ck[i+1][j] &ck[i+1][j+1]){
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
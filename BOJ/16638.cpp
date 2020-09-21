#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int, int> > a(n);
    for(int i=0;i<n;i++){
        if(i%2 == 0){
            a[i] = make_pair(s[i]-'0',0);
        }else {
            int op = 1;
            if (s[i]=='-'){
                op = 2;
            }else if (s[i]=='*'){
                op = 3;
            }
            a[i] = make_pair(0,op);
        }
    }
    int m = (n-1)/2;
    int ans = -2147483648;
    for(int i=0;i<(1<<m);i++){
        bool ok = true;
        for(int j=0;j<m-1;j++){
            if((i&(1<<j)) > 0 && (i&(1<<(j+1)))>0){
                ok = false;
            }
        }
        if(!ok) continue;
        vector<pair<int, int> > b = a;
        for(int j=0;j<m;j++){
            if((i&(1<<j))>0){
                int k = 2*j+1;
                if (b[k].second == 1){
                    b[k-1].first+=b[k+1].first;
                    b[k].second = -1;
                    b[k+1].first = 0;
                }else if (b[k].second == 2){
                    b[k-1].first-=b[k+1].first;
                    b[k].second = -1;
                    b[k+1].first = 0;
                }else if (b[k].second == 3){
                    b[k-1].first*=b[k+1].first;
                    b[k].second = -1;
                    b[k+1].first = 0;
                }
            }
        }
        vector<pair<int, int> > c;
        for(int j=0;j<n;j++){
            if(j%2 == 0){
                c.push_back(b[j]);
            }else {
                if(b[j].second == -1){
                    j++;
                }else {
                    if(b[j].second == 3){
                        int num = c.back().first * b[j+1].first;
                        c.pop_back();
                        c.push_back(make_pair(num,0));
                        j++;
                    }else {
                        c.push_back(b[j]);
                    }
                }
            }
        }
        b = c;
        int m2 = ((int)b.size()-1)/2;
        int res = b[0].first;
        for(int j=0;j<m2;j++){
            int k = 2*j+1;
            if (b[k].second == 1){
                res+=b[k+1].first;
            }else if(b[k].second == 2){
                res-=b[k+1].first;
            }
        }
        if(ans < res) ans = res;
    }
    cout << ans << '\n';
    return 0;
}
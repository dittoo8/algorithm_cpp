#include <iostream>
using namespace std;
int nums[27];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str1,str2;
    int ans = 0;
    cin >> str1 >> str2;
    for(int i=0;i<str1.length();i++){
        nums[str1[i]-'a']++;
    }
    for(int i=0;i<27;i++){
        cout << nums[i] << ' ';
    }
    for(int i=0;i<str2.length();i++){
        nums[str2[i]-'a']--;
    }
    cout << '\n';
    for(int i=0;i<27;i++){
        cout << nums[i] << ' ';
    }
    for(int i=0;i<27;i++){
        ans+=abs(nums[i]);
    }
    cout << ans << '\n';
    return 0;
}

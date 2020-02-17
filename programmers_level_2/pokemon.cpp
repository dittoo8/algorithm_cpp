#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int numSize = nums.size();
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    if (numSize/2 >= nums.size()){
        return (int)nums.size();
    } else {
        return numSize/2;
    }
}
int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << solution(v) << endl;
    return 0;
}
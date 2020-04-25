#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long d[111111];
int solution(int n, vector<int> money) {
  int answer = 0;
  d[0] = 1;
  for (int i=money[0] ; i<=n ; i+=money[0])
    d[i] = 1;
  for (int j=1 ; j<money.size() ; j++)
    for (int i=0 ; i<=n ; i++)
      if (i >= money[j])
        d[i] += d[i-money[j]] % 1000000007;
  answer = d[n];
  return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    cout << solution(5,v) <<endl;
    return 0;
}
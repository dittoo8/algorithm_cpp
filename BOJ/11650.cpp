#include <iostream>
#include <algorithm>
using namespace std;
int N;
pair<int, int> S[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> S[i].first >> S[i].second;
	}
	sort(S, S + N);
	for (int i = 0; i < N; ++i){
        cout << S[i].first << ' ' << S[i].second << '\n';
    }
		
    return 0;
}
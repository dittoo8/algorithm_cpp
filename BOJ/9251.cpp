#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int arr[1001][1001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j <s2.length(); j++) {
			if (s1[i] == s2[j]) {
				arr[i + 1][j + 1] = arr[i][j] + 1;
			} else {
				arr[i + 1][j + 1] = max(arr[i][j+1],arr[i+1][j]);
			}
		}
	}
	cout << arr[s1.length()][s2.length()] << '\n';
	return 0;
}
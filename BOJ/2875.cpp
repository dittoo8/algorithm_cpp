#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (;k > 0; k--){
		if (n >= (m * 2))
			n--;
		else if (n < (m * 2))
			m--;
	}
	if ((n / 2) < m)
		m = n / 2;
	cout << m;
	return 0;
}
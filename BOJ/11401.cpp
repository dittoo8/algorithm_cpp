#include<iostream>
#define P 1000000007
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long N, K, A = 1, B = 1, C = 1;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		A = (A * i) % P;
	for (int i = 1; i <= N - K; i++)
		B = (B * i) % P;
	for (int i = 1; i <= K; i++)
		C = (C * i) % P;
	
	long long ex = P - 2, mulB = B,mulC = C, ansB = 1, ansC = 1;
	while (ex) {
		if (ex % 2 == 1)
			ansB = (ansB * mulB) % P;
		mulB = (mulB * mulB) % P;
		ex /= 2;
	}

	ex = P - 2;
	while (ex) {
		if (ex % 2 == 1)
			ansC = (ansC * mulC) % P;
		mulC = (mulC * mulC) % P;
		ex /= 2;
	}
	cout << (((A * ansB) % P)* ansC) % P;
}
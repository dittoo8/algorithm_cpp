#include <iostream>
#define MAX 246913
using namespace std;
bool isPrime[MAX];
void eratosthenes() {
    for (int i=2; i<=MAX; i++) {
        if (!isPrime[i]) {
            for (int j=i*2; j<=MAX; j+=i) {
                isPrime[j] = true;
            }
        }
    }
} 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    eratosthenes();
    while(true) {
        int ans=0;
        cin>>n;
        if (n==0) {
            break;
        }
        for (int i=n+1; i<=2*n; i++) {
            if (!isPrime[i]) {
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

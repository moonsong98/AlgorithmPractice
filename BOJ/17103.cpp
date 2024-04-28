#include<iostream>
#include<vector>

using namespace std;

const int MAX = 1000000;
vector<bool> isPrime;
vector<int> primes;

void preCalc() {
	isPrime=vector<bool>(MAX+1, true);
	for(int i=2; i<=MAX; ++i) {
		if(isPrime[i]){
			primes.push_back(i);
			for(int j=2; i*i<=MAX && i*j<=MAX; ++j) {
				isPrime[i*j]=false;
			}
		}
	}
}

int main(void) {
	preCalc();
	int t;
	cin >> t;
	while(t--) {
		int a;
		int ans=0;
		cin >> a;
		for(int p: primes) {
			if(2*p>a) break;
			if(isPrime[a-p]) ans++;
		}
		cout << ans << '\n';
	}
}
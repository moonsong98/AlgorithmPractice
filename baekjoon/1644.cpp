#include<iostream>
#include<vector>

using namespace std;

int n;
vector<bool> isPrime;
vector<int> primes;

void preCalc() {
	isPrime=vector<bool>(n+1, true);
	for(int i=2; i<=n; ++i) {
		if(isPrime[i]){
			primes.push_back(i);
			for(int j=2; i*i<=n && i*j<=n; ++j) {
				isPrime[i*j]=false;
			}
		}
	}
}

int main(void) {
	cin >> n;
	preCalc();
	int low=-1, high=-1, sum=0, ans=0;
	while(high < (int)primes.size()) {
		if(sum<=n) {
			if(sum==n) ++ans;
			if(high+1==(int)primes.size()) break;
			sum+=primes[++high];
		} else sum-=primes[++low];
	}
	cout << ans << '\n';
}
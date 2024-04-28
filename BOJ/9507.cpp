#include<iostream>

using namespace std;

int main(void) {
	long long dp[68];
	dp[0]=dp[1]=1ll; dp[2]=2ll; dp[3]=4ll;
	for(int i=4; i<=67; ++i) dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
	int t; cin >> t;
	while(t--) {
		int a; cin >> a; cout << dp[a] << '\n';
	}
}
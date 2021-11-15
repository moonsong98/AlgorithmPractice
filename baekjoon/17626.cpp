#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	const int MAX=50000, INF=987654321;
	vector<int> dp(MAX+1, INF);
	for(int i=1; i*i<=MAX; ++i) dp[i*i]=1;
	for(int i=2; i<=MAX; ++i) {
		if(dp[i]==1) continue;
		for(int j=1; j*j<=i; ++j) 
			dp[i] = min(dp[i], dp[i-j*j]+1);
	}
	int n; cin >> n;
	cout << dp[n] << '\n';
}
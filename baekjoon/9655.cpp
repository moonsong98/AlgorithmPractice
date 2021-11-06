#include<iostream>
#include<vector>

using namespace std;

int dp[1001][2];

int main(void) {
	int n; cin >> n;
	dp[1][0]=dp[2][1]=dp[3][0]=0; dp[1][1]=dp[2][0]=dp[3][1]=1;
	for(int i=4; i<=n; ++i) {
		dp[i][0] = dp[i-1][1] & dp[i-3][1];
		dp[i][1] = dp[i-1][0] | dp[i-3][0];
	}
	cout << (dp[n][0] ? "CY" : "SK") << '\n';
}
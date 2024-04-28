#include<iostream>

using namespace std;

int main(void) {
	int dp[1001][2];
	dp[1][0]=dp[2][1]=dp[3][0]=1;
	dp[1][1]=dp[2][0]=dp[3][1]=0;
	for(int i=4; i<=1000; ++i) {
		dp[i][0]=dp[i-1][1]&dp[i-3][1];
		dp[i][1]=dp[i-1][0]|dp[i-3][0];
	}
	int n;
	cin >> n;
	cout << (dp[n][0]?"CY":"SK") << '\n';
}
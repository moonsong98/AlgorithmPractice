#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> b(n+1, vector<int>(m+1, 0));
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) cin >> b[i][j];
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			dp[i][j]=max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + b[i][j];
	
	cout << dp[n][m] << '\n';
}
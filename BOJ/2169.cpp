#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	vector<vector<int>> board(n+1, vector<int>(m+1));
	
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) cin >> board[i][j];
	
	for(int i=1; i<=m; ++i) dp[1][i]=dp[1][i-1]+board[1][i];
	for(int i=2; i<=n; ++i) {
		vector<int> L(m+1), R(m+1);
		L[1]=dp[i-1][1]+board[i][1];
		R[m]=dp[i-1][m]+board[i][m];
		for(int j=2; j<=m; ++j) L[j]=max(L[j-1], dp[i-1][j])+board[i][j];
		for(int j=m-1; j>=1; --j) R[j]=max(R[j+1], dp[i-1][j])+board[i][j];
		for(int j=1; j<=m; ++j) dp[i][j]=max(L[j], R[j]);
	}
	
	cout << dp[n][m] << '\n';
}
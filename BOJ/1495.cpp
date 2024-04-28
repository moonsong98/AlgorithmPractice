#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, s, m; cin >> n >> s >> m;
	vector<int> V(n+1); for(int i=1; i<=n; ++i) cin >> V[i];
	vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
	dp[0][s] = true;
	for(int i=0; i<n; ++i) for(int j=0; j<=m; ++j) 
		if(dp[i][j]) {
			if(j-V[i+1]>=0) dp[i+1][j-V[i+1]] = true;
			if(j+V[i+1]<=m) dp[i+1][j+V[i+1]] = true;
		}
	for(int i=m; i>=0; --i) 
		if(dp[n][i]) {
			cout << i << '\n';
			return 0;
		}
	cout << -1 << '\n';
}
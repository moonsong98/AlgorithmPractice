#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int dp[10001];

int main(void) {
	int t;
	cin >> t;
	while(t--) {
		memset(dp, 0, sizeof(dp));
		int n, m;
		cin >> n;
		vector<int> coins(n); for(int i=0; i<n; ++i) cin >> coins[i];
		cin >> m;
		dp[0]=1;

		for(int i=0; i<n; ++i) {
			for(int j=0; j<=m; ++j) {
				if(j+coins[i]<=m) dp[j+coins[i]]+=dp[j];
			}
		}
		cout << dp[m] << '\n';
	}
}
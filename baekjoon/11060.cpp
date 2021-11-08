#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	const int INF = 987654321;
	int n; cin >> n;
	vector<int> seq(n); for(int i=0; i<n; ++i) cin >> seq[i];
	vector<int> dp(n, INF); dp[0]=0;
	for(int i=0; i<n; ++i) 
		if(dp[i]!=INF)
			for(int j=1; j<=seq[i]; ++j) 
				if(i+j<n)
					dp[i+j]=min(dp[i+j], dp[i]+1);
	cout << (dp[n-1]==INF ? -1 : dp[n-1])  << '\n';
}
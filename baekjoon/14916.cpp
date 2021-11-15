#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	const int MAX=1e5, INF=987654321;
	vector<int> dp(MAX+1, INF); dp[2]=dp[5]=1;
	for(int i=4; i<=MAX; ++i) {
		if(i==5) continue;
		if(dp[i-2]!=INF) dp[i]=min(dp[i], dp[i-2]+1);
		if(i>5&&dp[i-5]!=INF) dp[i]=min(dp[i], dp[i-5]+1);
	}
	int n; cin >> n;
	cout << (dp[n]==INF?-1:dp[n]) << '\n';
}
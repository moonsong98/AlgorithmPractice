#include<iostream>

using namespace std;
const int INF = 987654321;

int coins[101], dp[10011];

int main(void) {
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; ++i) cin >> coins[i];
	for(int i=1; i<=k; ++i) {
		dp[i] = INF;
		for(int x: coins)
			if(i-x >= 0) dp[i]=min(dp[i], dp[i-x]+1);
	}
	cout << (dp[k] == INF ? -1 : dp[k]) << '\n';
}
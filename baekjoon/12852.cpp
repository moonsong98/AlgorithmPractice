#include<iostream>
#include<vector>

using namespace std;

const int INF=987654321;


int main(void) {
	int n;
	cin >> n;
	vector<int> dp(n+1, INF);
	dp[1]=0;
	for(int i=1; i<n; ++i) {
		if(i+1<=n) dp[i+1]=min(dp[i]+1, dp[i+1]);
		if(i*2<=n) dp[i*2]=min(dp[i]+1, dp[i*2]);
		if(i*3<=n) dp[i*3]=min(dp[i]+1, dp[i*3]);
	}
	vector<int> ans;
	ans.push_back(n);
	int itr=n;
	while(itr>1) {
		if(dp[itr-1]+1==dp[itr]) {
			ans.push_back(itr-1);
			--itr;
		}
		else if(!(itr%2) && dp[itr/2]+1==dp[itr]) {
			ans.push_back(itr/2);
			itr/=2;
		}
		else if(!(itr%3) && dp[itr/3]+1==dp[itr]) {
			ans.push_back(itr/3);
			itr/=3;
		}
	}
	cout << dp[n] << '\n';
	for(int a: ans) cout << a << ' ';
	cout << '\n';
}
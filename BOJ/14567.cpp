#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<int> dp;

void dfs(int u) {
	dp[u]=1;
	for(int v: adj[u]) {
		if(dp[v]==-1) dfs(v);
		dp[u]=max(dp[u], dp[v]+1);
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	
	dp=vector<int>(n+1,-1);
	adj=vector<vector<int>>(n+1, vector<int>());
	
	for(int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
	
	for(int i=1; i<=n; ++i) {
		if(dp[i]==-1) dfs(i);
		cout << dp[i] << ' ';
	}
	cout << '\n';
}
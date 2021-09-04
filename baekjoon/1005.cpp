#include<iostream>
#include<vector>

using namespace std;

vector<int> dp, bt;
vector<vector<int>> adj;

void dfs(int u) {
	dp[u]=0;
	for(int i=0; i<adj[u].size(); ++i) {
		int v=adj[u][i];
		if(dp[v]==-1) dfs(v);
		dp[u]=max(dp[u],dp[v]);
	}
	dp[u]+=bt[u];
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t, n, k, w;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		dp=vector<int>(n+1, -1);
		bt=vector<int>(n+1);
		adj=vector<vector<int>>(n+1, vector<int>());
		for(int i=1; i<=n; ++i) cin >> bt[i];
		for(int i=0; i<k; ++i) {
			int u, v;
			cin >> u >> v;
			adj[v].push_back(u);
		}
		cin >> w;
		dfs(w);
		cout << dp[w] << '\n';
	}
}
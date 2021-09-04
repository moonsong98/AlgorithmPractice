#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<int> w;
vector<int> dp;

void dfs(int u) {
	dp[u]=0;
	for(int i=0; i<adj[u].size(); ++i) {
		int v=adj[u][i];
		if(dp[v]==-1) dfs(v);
		dp[u]=max(dp[v], dp[u]);
	}
	dp[u]+=w[u];
}

int main(void) {
	int n, ans=0;
	cin >> n;
	adj=vector<vector<int>> (n+1, vector<int>());
	w=vector<int>(n+1);
	dp=vector<int>(n+1,-1);
	
	for(int i=1; i<=n; ++i) {
		cin >> w[i];
		int numWorks;
		cin >> numWorks;
		for(int j=0; j<numWorks; ++j) {
			int a;
			cin >> a;
			adj[i].push_back(a);
		} 
	}
	
	for(int i=1; i<=n; ++i) {
		if(dp[i]==-1) dfs(i);
		ans=max(ans,dp[i]);
	}
	cout << ans << '\n';
}
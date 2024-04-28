#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> w, dp, ans;
vector<bool> ri;

//u를 루트로 하는 subtree 에서 max independent set size
void dfs(int u){
	if(adj[u].size() == 0 || adj[u].size() == 1 && dp[adj[u][0]] != -1) {
		ri[u]=true;
		dp[u]=w[u];
		return;
	}
	dp[u]=w[u];
	int notInclude=0;
	for(int i=0; i<adj[u].size(); ++i) {
		int v=adj[u][i];
		if(dp[v] != -1) continue;
		dfs(v);
		notInclude+=dp[v];
		for(int j=0; j<adj[v].size(); ++j) 
			if(adj[v][j] != u) dp[u] += dp[adj[v][j]];
	}
	ri[u]=dp[u]>=notInclude;
	dp[u]=max(dp[u], notInclude);
}

void reconstruct(int u, int p) {
	if(ri[u]) {
		ans.push_back(u);
		for(int i=0; i<adj[u].size(); ++i) {
			int v=adj[u][i];
			if(v != p) 
				for(int j=0; j<adj[v].size(); ++j)
					if(adj[v][j] != u)
						reconstruct(adj[v][j], v);
		}
	}
	else {
		for(int i=0; i<adj[u].size(); ++i) {
			int v=adj[u][i];
			if(v != p) reconstruct(v, u);
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	adj=vector<vector<int>> (n+1, vector<int>());
	w=vector<int>(n+1);
	dp=vector<int>(n+1, -1);
	ri=vector<bool>(n+1, false);
	for(int i=1; i<=n; ++i) cin>>w[i];
	for(int i=1; i<n; ++i) {
		int u, v;
		cin >>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cout << dp[1] << '\n';
	reconstruct(1, -1);
	sort(ans.begin(), ans.end());	
	for(int a: ans) cout << a << ' ';
	cout << '\n';
}
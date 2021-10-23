#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
bool ans = false;

void dfs(int u, int cnt) {
	visited[u]=true;
	if(cnt==4) {
		ans=true; 
		return;
	}
	for(int v: adj[u]) {
		if(ans) return;
		if(!visited[v]) dfs(v,cnt+1);
	}
	visited[u]=false;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	adj=vector<vector<int>> (n, vector<int>());
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0; i<n && !ans; ++i) {
		visited.assign(n, false);
		dfs(i,0);	
	}
	cout << ans << '\n';	
}
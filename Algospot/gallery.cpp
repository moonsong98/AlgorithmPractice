#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int cnt=0;

int dfs(int u) {
	visited[u]=true;
	bool childState[3]={false,};
	for(int v: adj[u]) 
		if(!visited[v])
			childState[dfs(v)]=true;
	if(childState[2]) {
		++cnt;
		return 0;
	}
	if(childState[0]) return 1;
	return 2;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		int n, m; cin >> n >> m;
		cnt=0;
		adj=vector<vector<int>>(n);
		visited=vector<bool>(n, false);
		for(int i=0; i<m; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=0; i<n; ++i)
			if(!visited[i]&&dfs(i)==2) ++cnt;
		cout << cnt << '\n';
	}
}
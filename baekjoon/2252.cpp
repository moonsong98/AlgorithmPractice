#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> ans;
vector<bool> visited;

void dfs(int u) {
	visited[u]=true;
	for(int i=0; i< adj[u].size(); ++i) {
		int v=adj[u][i];
		if(!visited[v]) dfs(v);
	}
	ans.push_back(u);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	adj=vector<vector<int>>(n+1, vector<int>());
	visited=vector<bool>(n+1, false);
	for(int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	
	for(int i=1; i<=n; ++i) if(!visited[i]) dfs(i);
	
	reverse(ans.begin(), ans.end());
	for(int a: ans) cout << a << ' ';
	cout << '\n';
}
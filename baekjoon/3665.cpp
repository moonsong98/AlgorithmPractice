#include<bits/stdc++.h>
using namespace std;

int n;
bool valid;
vector<vector<bool>> adj;
vector<bool> finished;
vector<bool> visited;
vector<int> ans;
void dfs(int u) {
	visited[u]=true;
	for(int v=1; v<=n; ++v) {
		if(!adj[u][v]) continue;
		if(!visited[v]) dfs(v);
		else if(!finished[v]) {
			valid=false;
			return;
		}
	}
	finished[u]=true;
	ans.push_back(u);
}

int main(void) {
	cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int m; 
		cin >> n;
		valid=true;
		vector<int> v(n);
		adj=vector<vector<bool>>(n+1, vector<bool> (n+1, false));
		finished=vector<bool>(n+1, false);
		visited=vector<bool>(n+1, false);
		ans.clear();
		for(int &a: v) cin >> a;
		for(int i=0; i<n; ++i)
			for(int j=i+1; j<n; ++j)
				adj[v[i]][v[j]]=true;
		cin >> m;
		for(int i=0; i<m; ++i) {
			int u, v;
			cin >> u >> v;
			if(adj[u][v]) {
				adj[v][u]=true;
				adj[u][v]=false;
			}
			else {
				adj[v][u]=false;
				adj[u][v]=true;
			}
		}
		for(int i=1; i<=n; ++i)
			if(!visited[i])
				dfs(i);
		if(!valid) {
			cout << "IMPOSSIBLE" << '\n';
			continue;
		}
		reverse(ans.begin(), ans.end());
		for(int a: ans) cout << a << ' ';
		cout << '\n';
	}
}
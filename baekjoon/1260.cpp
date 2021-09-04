#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int n, m, k;

void dfs(int u) {
	visited[u]=true;
	cout << u << ' ';
	for(int i=0; i<adj[u].size(); ++i) {
		int v=adj[u][i];
		if(visited[v]) continue;
		dfs(v);
	}
}

void bfs(int start){
	queue<int> q;
	visited=vector<bool>(n+1, false);
	q.push(start);
	visited[start]=true;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		cout << u << ' ';
		for(int i=0; i<adj[u].size(); ++i) {
			int v=adj[u][i];
			if(visited[v]) continue;
			q.push(v);
			visited[v]=true;
		}
	}
	cout << '\n';
}

int main(void) {
	cin >> n >> m >> k;
	adj=vector<vector<int>>(n+1,vector<int>());
	visited=vector<bool>(n+1, false);
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n; ++i) sort(adj[i].begin(), adj[i].end());
	dfs(k);
	cout << '\n';
	bfs(k);
}
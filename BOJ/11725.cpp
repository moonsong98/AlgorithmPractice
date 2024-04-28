#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> adj[100001];
int parent[100001];
bool visited[100001];
int n;

void dfs(int node) {
	if(visited[node]) return;
	visited[node] = true;
	for(int i = 0; i < adj[node].size(); ++i) 
		if(parent[adj[node][i]] == -1) {
			parent[adj[node][i]] = node;
			dfs(adj[node][i]);
		}
}

int main(void) {
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	memset(parent, -1, sizeof(parent));
	parent[1] = 0;
	for(int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for(int i = 2; i <= n; ++i)
		cout << parent[i] << '\n';
}
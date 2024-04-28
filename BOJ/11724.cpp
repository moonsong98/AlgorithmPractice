#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void) {
	int n, m, ans=0;
	cin >> n >> m;
	vector<vector<int>> adj(n+1, vector<int>());
	vector<int> visited (n+1, false);
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i=1; i<=n; ++i) {
		if(!visited[i]) {
			queue<int> q;
			q.push(i);
			visited[i]=true;
			ans++;
			while(!q.empty()) {
				int u=q.front(); q.pop();
				for(int v: adj[u])
					if(!visited[v]) {
						q.push(v);
						visited[v]=true;
					}
			}
		}
	}
	cout << ans << '\n';
}
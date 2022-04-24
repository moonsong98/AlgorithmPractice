#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	set<int> s;
	vector<vector<pii>> adj(n+1);
	vector<int> dist(n+1, -1);
	for(int i=1; i<=n; ++i) {
		int a; cin >> a;
		if(i!=a) s.insert(a);
	}
	for(int i=0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	for(int i: s) {
		queue<int> q;
		q.push(i);
		while(!q.empty()) {
			int u=q.front(); q.pop();
			for(pii p: adj[u]) {
				int v=p.first, w=p.second;
				if(dist[u]==-1) {
					q.push(v);
					dist[v]=w;
				}
				else if(dist[v] < min(dist[u], w)) {
					q.push(v);
					dist[v]=min(dist[u], w);
				}
			}
		}
	}
	int ans=s.size()?INT_MAX:-1;
	for(int i:s) 
		ans=min(ans, dist[i]);
	cout << ans << '\n';
}

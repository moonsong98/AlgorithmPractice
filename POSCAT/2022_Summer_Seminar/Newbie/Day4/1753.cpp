#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int V, E, s; cin >> V >> E >> s;
	vector<vector<pair<int,int>>> adj(V+1);
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	vector<int> dist(V+1, INF);
	dist[s]=0;
	priority_queue<pair<int,int>> pq;
	pq.push({0, s});
	while(!pq.empty()) {
		int u=pq.top().second, distU=-pq.top().first;
		pq.pop();
		if(distU>dist[u]) continue;
		for(auto p: adj[u]) {
			int v=p.first, w=p.second;
			if(distU+w<dist[v]) {
				dist[v]=distU+w;
				pq.push({-dist[v], v});
			}
		}
	}
	for(int i=1; i<=V; ++i) {
		if(dist[i]==INF)
			cout << "INF" << '\n';
		else 
			cout << dist[i] << '\n';
	}
		
}
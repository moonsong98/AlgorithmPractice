#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int INF=1e9+7;

int main(void) {
	// ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		vector<vector<pii>> adj(n+1);
		for(int i=0; i<m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({w, v});
			adj[v].push_back({w, u});
		}
		vi dest;
		for(int i=0; i<a; ++i) {
			int u;
			cin >> u;
			dest.push_back(u);
		}
		for(int i=0; i<b; ++i) {
			int u;
			cin >> u;
			adj[0].push_back({0, u});
		}
		priority_queue<pii> pq;
		vi dist(n+1, INF);
		dist[0]=0;
		pq.push({0,0});
		while(!pq.empty()) {
			int u=pq.top().second, cost=-pq.top().first;
			pq.pop();
			if(dist[u]<cost) continue;
			for(pii p: adj[u]) {
				int v=p.second, w=p.first;
				if(dist[v]>w+cost){
					dist[v]=w+cost;
					pq.push({-dist[v], v});
				}
			}
		}
		int ans=0;
		for(int d: dest) ans+=dist[d];
		cout << ans << '\n';
	}
}
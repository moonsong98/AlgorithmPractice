#include<bits/stdc++.h>

using namespace std;
typedef pair<double,int> pdi;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cout<<fixed;
	cout.precision(10);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<pdi>> adj(n);
		vector<double> dist(n, numeric_limits<double>::max());
		for(int i=0; i<m; ++i) {
			int u, v;
			double w;
			cin >> u >> v >> w;
			adj[u].push_back({w, v});
			adj[v].push_back({w, u});
		}
		priority_queue<pdi> pq;
		pq.push({-1.0,0});
		dist[0]=1.0;
		while(!pq.empty()){
			double cost=-pq.top().first;
			int u=pq.top().second;
			pq.pop();
			if(dist[u]<cost) continue;
			for(pdi p: adj[u]) {
				double w=p.first;
				int v=p.second;
				if(cost*w<dist[v]) {
					dist[v]=cost*w;
					pq.push({-dist[v], v});
				}
			}
		}
		cout << dist[n-1] << '\n';
	}
}
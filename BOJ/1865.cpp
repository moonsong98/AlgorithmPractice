#include<bits/stdc++.h>

using namespace std;

const int INF=1e9+7;

int main(void) {
	int t;
	cin >> t;
	while(t--) {
		ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
		int V, E1, E2;
		cin >> V >> E1 >> E2;
		vector<vector<int>> adj(V+1, vector<int>(V+1, INF));
		vector<int> upper(V+1, INF);
		for(int i=0; i<E1; ++i) {
			int s, e, t;
			cin >> s >> e >> t;
			adj[s][e]=min(adj[s][e],t);
			adj[e][s]=min(adj[e][s],t);
		}
		for(int i=0; i<E2; ++i) {
			int s, e, t;
			cin >> s >> e >> t;
			adj[s][e]=min(adj[s][e],-t);
		}
		for(int i=1; i<=V; ++i) adj[0][i]=0;
		upper[0]=0;
		bool updated=false;
		for(int k=0; k<=V; ++k) {
			updated=false;
			for(int u=0; u<=V; ++u) {
				if(upper[u]==INF) continue;
				for(int v=0; v<=V; ++v) {
					if(upper[v]>upper[u]+adj[u][v]) {
						upper[v]=upper[u]+adj[u][v];
						updated=true;
					}
				}
			}
			if(!updated) break;
		}
		cout << (updated?"YES":"NO") << '\n';
	}
}
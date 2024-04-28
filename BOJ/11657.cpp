#include<iostream>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll INF=987654321;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>());
	vector<ll> upper(n+1, INF); upper[1]=0;
	for(int i=0; i<m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	bool updated=false;
	for(int iter=0; iter<n; ++iter) {
		updated=false;
		for(int u=1; u<=n; ++u) {
			if(upper[u]==INF) continue;
			for(pair<int,int> p: adj[u]) {
				int v=p.first, w=p.second;
				if(upper[u]+w < upper[v]) {
					upper[v]=upper[u]+w;
					updated=true;
				}
			}
		}
		if(!updated) break;
	}
	if(updated) cout << -1 << '\n';
	else for(int i=2; i<=n; ++i) cout << (upper[i]==INF?-1:upper[i]) << '\n';
}
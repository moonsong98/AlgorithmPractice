#include<bits/stdc++.h>

using namespace std;

const int INF=1e9+7;

void reconstruct(vector<vector<int>> &dist, vector<vector<int>> &via, int u, int v, vector<int> &path) {
	if(via[u][v]==INF) {
		path.push_back(u);
		if(u!=v)
			path.push_back(v);
	}
	else {
		int w=via[u][v];
		reconstruct(dist,via,u,w,path);
		path.pop_back();
		reconstruct(dist,via,w,v,path);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; 
	cin >> n >> m;
	vector<vector<int>> dist(n+1, vector<int> (n+1, INF));
	vector<vector<int>> via(n+1, vector<int> (n+1, INF));
	for(int i=0; i<m; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		dist[s][e]=min(dist[s][e],c);
	}
	for(int i=1; i<=n; ++i) dist[i][i]=0;
	for(int k=1; k<=n; ++k) 
		for(int u=1; u<=n; ++u) {
			if(dist[u][k]==INF) continue;
			for(int v=1; v<=n; ++v) 
				if(dist[u][v]>dist[u][k]+dist[k][v]) {
					via[u][v]=k;
					dist[u][v]=dist[u][k]+dist[k][v];
				}
		}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j)
			cout << (dist[i][j]==INF?0:dist[i][j]) << ' ' ;
		cout << '\n';
	}
	vector<int> path;
	for(int u=1; u<=n; ++u)
		for(int v=1; v<=n; ++v) {
			if(u==v||dist[u][v]==INF) cout << 0 << '\n';
			else {
				path.clear();
				reconstruct(dist, via, u, v, path);
				cout << path.size() << ' ';
				for(int p: path) cout << p << ' ';
				cout << '\n';
			}
		}
		
}

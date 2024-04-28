#include<bits/stdc++.h>

using namespace std;

int main(void) {
	int V, E, M, S, x, y; cin >> V >> E;
	vector<vector<pair<int,int>>> adj(V+3, vector<pair<int,int>>()); //adj[V] = M, adj[V+1] = S
	vector<bool> isHouse(V+3, true); isHouse[V+1]=isHouse[V+2]=false;
	for(int i=0; i<E; ++i) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	cin >> M >> x; for(int i=0; i<M; ++i) {
		int a; cin >> a;
		adj[V+1].push_back({a, 0});
		isHouse[a]=false;
	}
	cin >> S >> y; for(int i=0; i<S; ++i) {
		int a; cin >> a;
		adj[V+2].push_back({a, 0});
		isHouse[a]=false;
	}
	priority_queue<pair<int,int>> pq;
	vector<int> distM(V+3, -1); distM[V+1]=0; 
	vector<int> distS(V+3, -1); distS[V+2]=0;
	pq.push({0, V+1});
	while(!pq.empty()) {
		int u=pq.top().second, cost=-pq.top().first; pq.pop();
		if(cost > distM[u]) continue;
		for(pair<int,int> p: adj[u]) {
			int v=p.first, w=p.second, newDist=distM[u]+w;
			if(distM[v]==-1 || newDist<distM[v]) {
				distM[v]=newDist;
				pq.push({-newDist, v});
			}
		}
	}
	pq.push({0, V+2});
	while(!pq.empty()) {
		int u=pq.top().second, cost=-pq.top().first; pq.pop();
		if(cost > distS[u]) continue;
		for(pair<int,int> p: adj[u]) {
			int v=p.first, w=p.second, newDist=distS[u]+w;
			if(distS[v]==-1 || newDist<distS[v]) {
				distS[v]=newDist;
				pq.push({-newDist, v});
			}
		}
	}
	int ans=-1;
	for(int i=1; i<=V; ++i) {
		if(isHouse[i] && distM[i]<=x && distS[i]<=y) {
			int distSum=distM[i]+distS[i];
			ans = (ans==-1?distSum : min(ans, distSum));
		}
	}
	cout << ans << '\n'; 
}
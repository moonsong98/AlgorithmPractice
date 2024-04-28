#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX=987654321;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, s, e; cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>());
	priority_queue<pair<int,int>> pq;
	vector<int> ans;
	vector<int> dist(n+1, MAX);
	vector<int> parent(n+1); for(int i=0; i<=n; ++i) parent[i]=i;
	vector<bool> visited(n+1, false);
	for(int i=0; i<m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}
	cin >> s >> e;
	dist[s]=0;
	while(true) {
		int closest=MAX, u=-1;
		for(int i=1; i<=n; ++i) 
			if(closest > dist[i] && !visited[i]) {
				closest=dist[i];
				u=i;
			}
		if(u==-1) break;
		visited[u]=true;
		for(pair<int,int> p: adj[u]) {
			int v=p.first, w=p.second;
			if(visited[v]) continue;
			if(dist[v] > dist[u]+w) {
				dist[v]= dist[u]+w;
				parent[v]=u;
			}
		}
	}
	cout << dist[e] << '\n';
	ans.push_back(e);
	while(e!=parent[e]) {
		ans.push_back(parent[e]);
		e=parent[e];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int a: ans) cout << a << ' ';
}

/*
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, s, e; cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>());
	priority_queue<pair<int,int>> pq;
	vector<int> ans;
	vector<int> dist(n+1, MAX);
	vector<int> parent(n+1); for(int i=0; i<=n; ++i) parent[i]=i;
	for(int i=0; i<m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}
	cin >> s >> e;
	pq.push({0, s});
	dist[s]=0;
	while(!pq.empty()) {
		int u=pq.top().second, cost=-pq.top().first; pq.pop();
		if(cost>dist[u]) continue;
		for(pair<int,int> p: adj[u]) {
			int v=p.first, w=p.second;
			if(dist[v] > dist[u]+w) {
				dist[v]=dist[u]+w;
				pq.push({-(dist[u]+w), v});
				parent[v]=u;
			}
		}
	}
	cout << dist[e] << '\n';
	ans.push_back(e);
	while(parent[e]!=e) {
		ans.push_back(parent[e]);
		e=parent[e];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int a: ans) cout << a << ' ';
	cout << '\n';
}
*/
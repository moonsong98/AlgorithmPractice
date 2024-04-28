#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<long long,vector<int>> pivi;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	map<long long, pivi> cache;
	vector<bool> visited;
	set<int> ans2;
	vector<vector<pii>>adj(n+1);
	vector<int> in(n+1, 0), in2(n+1, 0);
	for(int i=0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		++in[v];
	}
	int start, dest;
	cin >> start >> dest;
	queue<int> q;
	q.push(start);
	for(int i=0; i<=n; ++i) cache[i].first=0;
	while(!q.empty()) {
		int u=q.front(); q.pop();
		long long cur=cache[u].first;
		for(pii p: adj[u]) {
			int v=p.first, w=p.second;
			if(cache[v].first<=cur+w) {
				if(cache[v].first<cur+w) {
					for(int a: cache[v].second) in2[a]--;
					cache[v].second.clear();
					cache[v].first=cur+w;
				}
				cache[v].second.push_back(u);
				in2[u]++;
			}
			if(!(--in[v])) q.push(v);
		}
	}
	visited=vector<bool>(n+1, false);
	stack<int> s; s.push(dest);
	while(!s.empty()) {
		int u=s.top(); s.pop();
		ans2.insert(u);
		for(int v: cache[u].second)
			if(!visited[v])
				s.push(v);
	}
	int ans=0;
	for(int u: ans2) ans+=cache[u].second.size();
	
	cout << cache[dest].first << '\n';
	cout << ans << '\n';
}

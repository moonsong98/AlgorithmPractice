#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1, vector<int>());
	vector<int> prerequisite(n+1, 0);
	priority_queue<int> pq;
	for(int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		prerequisite[b]++;
	}
	
	for(int i=1; i<=n; ++i) if(!prerequisite[i]) pq.push(-i);
	
	while(!pq.empty()) {
		int u=-pq.top(); pq.pop(); cout << u << ' ';
		for(int v:adj[u]) {
			--prerequisite[v];
			if(!prerequisite[v]) pq.push(-v);
		}
	}
	cout << '\n';
}
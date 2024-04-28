#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void) {
	int n; cin >> n;
	vector<vector<int>>adj(n+1);
	vector<int>level(n+1, -1);
	vector<int>parent(n+1, -1);
	for(int i=0; i+1<n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	level[1]=0;
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(int v: adj[u]) 
			if(level[v]==-1) {
				level[v]=level[u]+1;
				parent[v]=u;
				q.push(v);
			}
	}
	bool ans=true;
	int a; cin >> a;
	vector<int>orderSameLevel(n+1, 0);
	vector<int>order(n+1,-1);
	for(int i=1; i<n; ++i) {
		int b; cin >> b;
		if(level[a]>level[b]||(level[a]==level[b]&&order[parent[a]]>order[parent[b]])) {
			ans=false;
			break;
		}
		order[b]=orderSameLevel[level[b]]++;
		a=b;
	}
	cout << ans << '\n';
}
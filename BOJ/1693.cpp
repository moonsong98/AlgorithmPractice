#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> cache;

int dfs(int u, int col, int p) {
	int &ret=cache[u][col];
	if(ret!=-1) return ret;
	ret=col;
	for(int v: adj[u]) {
		if(v==p) continue;
		int minCost=INT_MAX;
		for(int i=1; i<=18; ++i){
			if(i==col) continue;
			minCost=min(minCost, dfs(v, i, u));
		}
		ret+=minCost;
	}
	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int N; cin >> N;
	adj=vector<vector<int>> (N+1);
	cache=vector<vector<int>> (N+1, vector<int>(19, -1));
	for(int i=0; i+1<N; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	adj[0].push_back(1);
	cout << dfs(0, 0, 0) << '\n';
}
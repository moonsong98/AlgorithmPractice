#include<bits/stdc++.h>
using namespace std;

int compNum_g;
vector<vector<int>> adj;
vector<int> v2c;
string breed;

void dfs(int u, int compNum) {
	v2c[u]=compNum;
	for(int v: adj[u])
		if(v2c[v]==-1)
			if(breed[u-1]==breed[v-1]) dfs(v, compNum);
			else dfs(v, compNum_g++);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int N, M; cin >> N >> M >> breed;
	adj=vector<vector<int>>(N+1);
	v2c=vector<int>(N+1, -1);
	for(int i=0; i+1<N; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, compNum_g++);
	for(int i=0; i<M; ++i) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		if(v2c[u]==v2c[v] && c==breed[u-1]) cout << "1";
		else if(v2c[u]!=v2c[v]) cout << "1";
		else cout << "0";
	}
	cout << '\n';
}
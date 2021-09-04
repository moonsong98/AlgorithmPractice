#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<int> nodeNum;


void dfs(int n) {
	nodeNum[n]=1;
	for(int i=0; i<adj[n].size(); ++i) {
		if(nodeNum[adj[n][i]]!=-1) continue;
		dfs(adj[n][i]);
		nodeNum[n]+=nodeNum[adj[n][i]];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n, r, q;
	cin >> n >> r >> q;
	
	adj=vector<vector<int>> (n+1, vector<int>());
	nodeNum=vector<int>(n+1, -1);
	
	for(int i=0; i+1<n; ++i){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(r);
	for(int i=0; i<q; ++i){
		int a;
		cin >> a;
		cout << nodeNum[a] << '\n';
	}
}
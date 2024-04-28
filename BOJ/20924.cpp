#include<iostream>
#include<vector>
#include<utility>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<bool> visited;
int branchLen=0, stemLen=0, ggNum=-1;

int dfs(int u) {
	visited[u]=true;
	int ret=0;
	if(ggNum==-1) {
		int cntChild=0;
		for(int i=0; i<adj[u].size(); ++i){
			int v=adj[u][i].first;
			if(!visited[v]) cntChild++;	
		}
		if(cntChild>=2) ggNum=u;
	}
	
	if(ggNum==-1) {
		for(int i=0; i<adj[u].size(); ++i){
			int v=adj[u][i].first;
			int w=adj[u][i].second;
			if(!visited[v]) {
				stemLen+=w;
				dfs(v);
				return 0;
			}
		}
	}
	else {
		for(int i=0; i<adj[u].size(); ++i) {
			int v=adj[u][i].first;
			int w=adj[u][i].second;
			if(!visited[v]) {
				ret=max(ret, w+dfs(v));
			}
		}
	}
	branchLen=max(branchLen, ret);
	return ret;
}

int main(void) {
	int n, r;
	cin >> n >> r;
	adj=vector<vector<pair<int,int>>>(n+1, vector<pair<int,int>>());
	visited=vector<bool>(n+1, false);
	for(int i=0; i+1<n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	
	dfs(r);
	cout << stemLen << " " << branchLen << '\n';
	// cout << ggNum << '\n';
}
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm> 

using namespace std;

vector<vector<int>> adj;
vector<int> found;
vector<pair<int,int>> ans;
int counter=0;

int dfs(int u, int parent) {
	int ret = found[u]=++counter;
	for(int i=0; i<adj[u].size(); ++i) {
		int v=adj[u][i];
		if(v==parent) continue;
		if(found[v]==-1) {
			int lowV=dfs(v,u);
			if(lowV>found[u]) {
				if(u<v) ans.push_back({u,v});
				else ans.push_back({v,u});
			}
			ret=min(ret, lowV);
		} else {
			ret=min(ret, found[v]);
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int v, e;
	cin >> v >> e;
	
	adj=vector<vector<int>> (v+1, vector<int>());
	found=vector<int>(v+1, -1);
	
	for(int i=0; i<e; ++i) {
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i=1; i<=v; ++i) 
		if(found[i] == -1) dfs(i,-1);
	
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int i=0; i<ans.size(); ++i) cout << ans[i].first << " " << ans[i].second << '\n';
}
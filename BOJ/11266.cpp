#include<iostream>
#include<vector>

using namespace std;

vector<bool> isCV;
vector<int> found;
vector<int> lowest;
vector<vector<int>> adj;
int v, e, cntCV=0;

void dfs(int u, bool isRoot) {
	int numChild=0;
	int &ret=lowest[u];
	found[u]=cntCV++;
	ret=found[u];
	for(int i=0; i<adj[u].size(); ++i){
		int v=adj[u][i];
		if(found[v]==-1){
			numChild++;
			dfs(v, false);
			if(lowest[v]>=found[u]) isCV[u]=true;
			ret=min(ret, lowest[v]);
		}
		else
			ret=min(ret, found[v]);
	}
	if(isRoot) isCV[u]=(numChild>=2);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> v >> e;

	adj=vector<vector<int>>(v+1,vector<int>());
	isCV=vector<bool>(v+1,false);	
	found=vector<int>(v+1, -1);
	lowest=vector<int>(v+1, -1);
	
	for(int i=0; i<e; ++i){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i=1; i<=v; ++i)
		if(found[i]==-1)
			dfs(i, true);
	
	int cnt=0;
	vector<int> ans;
	for(int i=1; i<=v; ++i)
		if(isCV[i]){
			cnt++;
			ans.push_back(i);
		}
	
	cout << cnt << '\n';
	for(int a: ans) cout << a << ' ';
	cout << '\n';
}
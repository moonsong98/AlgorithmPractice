#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> isEA;
vector<int> dp;

int dfs(int node) {
	int& ret=dp[node]=0;
	if(adj[node].size() == 0) return ret=1; // only one node
	bool isChildrenEA=true;
	bool isLeaf=true;	
	for(int i=0; i<adj[node].size(); ++i) {
		if(dp[adj[node][i]]!=-1) continue;
		isLeaf=false;
		ret+=dfs(adj[node][i]);
		isChildrenEA=isChildrenEA&&isEA[adj[node][i]];
	}
	isEA[node]=!isLeaf&&!isChildrenEA;
	return ret=(isEA[node]?ret+1:ret);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin>>n;
	adj=vector<vector<int>>(n+1, vector<int>());
	isEA=vector<bool>(n+1,false);
	dp=vector<int>(n+1,-1);
	
	for(int i=0; i+1<n; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	cout << dfs(1) << '\n';
}
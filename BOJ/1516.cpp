#include<iostream>
#include<vector>

using namespace std;

vector<int> dp;
vector<int> bt;
vector<vector<int>> adj;

void dfs(int u) {
	dp[u]=0;
	for(int i=0; i<adj[u].size(); ++i) {
		int v=adj[u][i];
		if(dp[v]==-1) dfs(v);
		dp[u]=max(dp[u],dp[v]);
	}
	dp[u]+=bt[u];
}

int main(void) {
	int n;
	cin >> n;
	
	dp=vector<int>(n+1, -1);
	bt=vector<int>(n+1, -1);
	adj=vector<vector<int>>(n+1, vector<int>());
	for(int i=1; i<=n; ++i) {
		while(true) {
			int a;
			cin >> a;
			if(a==-1) break;
			if(bt[i]==-1) bt[i]=a; 
			else adj[i].push_back(a);
		}
	}
	for(int i=1; i<=n; ++i) {
		if(dp[i] == -1) dfs(i);
		cout << dp[i] << '\n';
	}
}
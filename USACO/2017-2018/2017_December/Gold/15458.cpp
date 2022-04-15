#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> selected;
vector<vector<long long>> dp;
const long long MOD=1e9+7;

void dfs(int u, int p) {
	bool isLeaf=true;
	for(int v: adj[u])
		if(v!=p) {
			dfs(v, u);
			isLeaf=false;
		}
	if(isLeaf)
		if(selected[u]!=-1)
			for(int i=1; i<=3; ++i) dp[u][i]=(i==selected[u]);
		else
			for(int i=1; i<=3; ++i) dp[u][i]=1;
	else
		if(selected[u]!=-1) {
			dp[u][selected[u]]=1ll;
			for(int v: adj[u]) {
				if(v==p) continue;
				long long sum=0;
				for(int i=1; i<=3; ++i) {
					if(i==selected[u]) continue;
					sum+=dp[v][i];
				}
				dp[u][selected[u]]=(dp[u][selected[u]]*sum)%MOD;
			}
		}
		else {
			dp[u][1]=dp[u][2]=dp[u][3]=1ll;
			for(int i=1; i<=3; ++i) {
				for(int v: adj[u]) {
					if(v==p) continue;
					long long sum=0;
					for(int j=1; j<=3; ++j) {
						if(j==i) continue;
						sum+=dp[v][j];
					}
					dp[u][i]=(dp[u][i]*sum)%MOD;
				}
			}
		}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	adj=vector<vector<int>>(N+1);
	dp=vector<vector<long long>>(N+1, vector<long long>(4));
	selected=vector<int>(N+1, -1);
	for(int i=0; i+1<N; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0; i<K; ++i) {
		int u, c;
		cin >> u >> c;
		selected[u]=c;
	}
	dfs(1, 1);
	cout << (dp[1][1]+dp[1][2]+dp[1][3])%MOD << '\n';
}
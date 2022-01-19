#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, r; cin >> n >> m >> r;
	vector<int> items(n+1, 0); for(int i=1; i<=n; ++i) cin >> items[i];
	vector<vector<int>> adj(n+1, vector<int>(n+1, -1));
	for(int i=0; i<r; ++i) {
		int a, b, c; cin >> a >> b >> c;
		adj[a][b]=adj[b][a]=c;
	}
	for(int i=1; i<=n; ++i) adj[i][i]=0;
	for(int k=1; k<=n; ++k) for(int i=1; i<=n; ++i) if(adj[i][k]!=-1) for(int j=1; j<=n; ++j)
		if(adj[k][j]!=-1 && (adj[i][j]==-1 || adj[i][j] > adj[i][k]+adj[k][j]))
			adj[i][j]=adj[i][k]+adj[k][j];
	
	int ans=0;
	for(int i=1; i<=n; ++i) {
		int sum=0;
		for(int j=1; j<=n; ++j)
			if(adj[i][j]!=-1 && adj[i][j] <= m) sum+=items[j];
		ans=max(ans,sum);
	}
	cout << ans << '\n';
}
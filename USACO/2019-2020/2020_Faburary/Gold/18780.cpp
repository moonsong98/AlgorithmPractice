#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<int> order, ans, minAns;
vector<bool> visited;
vector<vector<pii>> adj;

void dfs(int u) {
	visited[u]=true;
	for(auto p: adj[u])
		if(visited[p.first]==false)
			dfs(p.first);
	order.push_back(u);
}

void solve(int u) {
	visited[u]=true;
	for(pii p: adj[u]) {
		int v=p.first, x=p.second;
		if(ans[v]==-1) {
			ans[v]=max(minAns[v], ans[u]+x);
			solve(v);
		}
		else if(ans[v] < ans[u]+x) {
			ans[v]=ans[u]+x;
			solve(v);
		}
	}
}


int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	int n, m, c;
	cin >> n >> m >> c;
	visited=vector<bool>(n+1, false);
	ans=vector<int>(n+1, -1);
	minAns=vector<int>(n+1);
	adj=vector<vector<pii>>(n+1);
	for(int i=1; i<=n; ++i) cin >> minAns[i];
	for(int i=0; i<c; ++i) {
		int a, b, x;
		cin >> a >> b >> x;
		adj[a].push_back({b, x});
	}
	for(int i=1; i<=n; ++i)
		if(visited[i]==false)
			dfs(i);
	
	reverse(order.begin(), order.end());
	fill(visited.begin(), visited.end(), false);
	for(int u: order) {
		if(visited[u]==false) {
			ans[u]=minAns[u];
			solve(u);
		}
	}
	for(int i=1; i<=n; ++i) cout << ans[i] << '\n';
}
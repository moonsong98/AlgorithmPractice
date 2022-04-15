#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

vector<vector<int>> adj, c2v;
vector<int> v2c;
vector<long long>srcCost, dstCost;;

long long sqr(long long a) {
	return a*a;
}

void clear() {
	for(vector<int> v: adj) v.clear();
	adj.clear();
	for(vector<int> v: c2v) v.clear();
	c2v.clear();
	v2c.clear();
}

void dfs(int u, int compId) {
	v2c[u]=compId;
	for(int v: adj[u])
		if(v2c[v]==-1)
			dfs(v, compId);
}

void solve() {
	int n, m;
	cin >> n >> m;
	adj=vector<vector<int>>(n+1);
	v2c=vector<int>(n+1, -1);
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int compNum=0;
	for(int i=1; i<=n; ++i)
		if(v2c[i]==-1)
			dfs(i, compNum++);
	if(v2c[1]==v2c[n]) {
		cout << 0 << '\n';
		return;
	}
	c2v=vector<vector<int>> (compNum);
	for(int i=1; i<=n; ++i)
		c2v[v2c[i]].push_back(i);
	long long ans=LLONG_MAX;
	for(int i=0; i<compNum; ++i) {
		long long srcCost=LLONG_MAX, dstCost=LLONG_MAX;
		for(int u: c2v[i]) {
			int pos=lower_bound(c2v[v2c[1]].begin(), c2v[v2c[1]].end(), u)-c2v[v2c[1]].begin();
			if(pos>0) srcCost=min(srcCost, sqr(c2v[v2c[1]][pos-1]-u));
			if(pos<sz(c2v[v2c[1]])) srcCost=min(srcCost, sqr(c2v[v2c[1]][pos]-u));
			pos=lower_bound(c2v[v2c[n]].begin(), c2v[v2c[n]].end(), u)-c2v[v2c[n]].begin();
			if(pos>0) dstCost=min(dstCost, sqr(c2v[v2c[n]][pos-1]-u));
			if(pos<sz(c2v[v2c[n]])) dstCost=min(dstCost, sqr(c2v[v2c[n]][pos]-u));
		}
		ans=min(ans, srcCost+dstCost);
	}
	cout << ans << '\n';
	clear();
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
		solve();
}
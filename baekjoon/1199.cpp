#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int N, cntEdge;
vvi adj;
vi numEdges, leftEdges, ans;
vector<pii> edges;

void dfs(int cur) {
	while(sz(adj[cur])>0) {
		int e=adj[cur].back();
		if(leftEdges[e]) {
			--leftEdges[e];
			int u=edges[e].first, v=edges[e].second;
			u==cur?dfs(v):dfs(u);
		}
		else
			adj[cur].pop_back();
	}
	ans.push_back(cur);
}

int main(void) {
	cin >> N;
	adj=vvi(N+1);
	numEdges=vi(N+1);
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j) {
			int a; cin >> a;
			if(i>=j || !a) continue;
			edges.push_back({i,j});
			leftEdges.push_back(a);
			numEdges[i]+=a;
			numEdges[j]+=a;
			adj[i].push_back(cntEdge);
			adj[j].push_back(cntEdge++);
		}
	}
	for(int i=1; i<=N; ++i)
		if(numEdges[i]%2) {
			cout << "-1\n";
			return 0;
		}
	
	dfs(1);
	for(int a: ans) cout << a << ' ';
	cout << '\n';
}

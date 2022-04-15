#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;

vector<vector<pii>> adj;
int dfs(int u, int parent, int M, int k) {
	int ret=0;
	for(auto p: adj[u]) {
		if(p.fi==parent) continue;
		if(min(M,p.se)>=k) ++ret;
		ret+=dfs(p.fi, u, min(M,p.se), k);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, Q;
	cin >> N >> Q;
	adj=vector<vector<pii>>(N+1);
	for(int i=0; i+1<N; ++i) {
		int p, q, r;
		cin >> p >> q >> r;
		adj[p].push_back({q, r});
		adj[q].push_back({p, r});
	}
	for(int q=0; q<Q; ++q) {
		int k, v;
		cin >> k >> v;
		cout << dfs(v, -1, 1e9+7, k) << '\n';
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) (int)x.size()
long long const INF=1e9+7;

ll ans=0;
vector<ll> values;
vector<vector<ll>> adj;

ll dfs(int u) {
	if(sz(adj[u])==0) return values[u];
	if(sz(adj[u])==1) return max(values[u], dfs(adj[u][0]));
	ll minValue=INF, childSum=0;
	for(int v: adj[u]) {
		ll childValue=dfs(v);
		childSum+=childValue;
		minValue=min(minValue,childValue);
	}
	ans+=childSum-minValue;
	return max(values[u],minValue);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	for(int tt=1; tt<=T; ++tt) {
		ans=0;
		cout << "Case #" << tt << ": ";
		int N; cin >> N;
		values=vector<ll>(N+1);
		adj=vector<vector<ll>> (N+1);
		for(int i=1; i<=N; ++i) cin >> values[i];
		for(int v=1; v<=N; ++v) {
			int u; cin >> u;
			adj[u].push_back(v);
		}
		ans+=dfs(0);
		cout << ans << '\n';
	}
}
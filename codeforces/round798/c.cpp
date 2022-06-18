#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> subSize;
vector<bool> visited;
int ans;

int calcSubSize(int u) {
	visited[u]=true;
	for(int v: adj[u]) {
		if(!visited[v])
			subSize[u]+=(1+calcSubSize(v));
	}
	return subSize[u];
}

int main(void) {
	//ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		ans=0;
		int n; cin >> n;
		adj=vector<vector<int>>(n+1);
		subSize=vector<int>(n+1, 0);
		for(int i=0; i+1<n; ++i){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		visited=vector<bool> (n+1, false);
		calcSubSize(1);
		visited=vector<bool> (n+1, false);
		queue<int> q;
		q.push(1);
		visited[1]=true;
		while(!q.empty()) {
			priority_queue<pair<int,int>> pq;
			queue<int> cand;
			while(!q.empty()) {
				int u=q.front(); q.pop();
				for(int v: adj[u]) 
					if(!visited[v]) {
						cand.push(v);
						visited[v]=true;
						pq.push({subSize[v], v});
					}
			}
			if(pq.empty()) break;
			ans+=pq.top().first;
			while(!cand.empty()) {
				int u=cand.front();
				cand.pop();
				if(u==pq.top().second) continue;
				q.push(u);
			}
		}
		cout << ans << '\n';
	}
}
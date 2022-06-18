#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> dist(N+1, INT_MAX);
	vector<vector<int>> comp(K+1);
	vector<int> compNum(N+1);
	vector<vector<int>> adj(K+1);
	vector<bool> communicateOwn(K+1, false);
	priority_queue<pii> pq;
	for(int i=1; i<=N; ++i) {
		int a; cin >> a;
		comp[a].push_back(i);
		compNum[i]=a;
	}
	for(int i=1; i<=K; ++i) for(int j=1; j<=K; ++j) {
		char a; cin >> a;
		if(a-'0'==1) {
			if(i!=j) adj[i].push_back(j);
			else communicateOwn[i]=true;
		}
	}
	dist[1]=0;
	pq.push({0, 1});
	while(!pq.empty()) {
		int cost=-pq.top().first, u=pq.top().second, compN=compNum[u];
		pq.pop();
		if(cost>dist[u]) continue;
		if(communicateOwn[compN]) {
			for(int v: comp[compN]) {
				int nCost=cost+abs(u-v);
				if(dist[v]>nCost) {
					dist[v]=nCost;
					pq.push({-nCost, v});
				}
			}
		}
		for(int c: adj[compN]) {
			for(int v: comp[c]) {
				int nCost=cost+abs(u-v);
				if(dist[v]>nCost) {
					dist[v]=nCost;
					pq.push({-nCost, v});
				}
			}
		}
	}
	cout << (dist[N]==INT_MAX?-1:dist[N]) << '\n';
}
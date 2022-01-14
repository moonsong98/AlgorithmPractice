#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

const int MAX=987654321;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>());
	vector<int> dist1(n+1, -1), distu(n+1,-1), distv(n+1,-1);
	for(int i=0; i<m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	int u, v; cin >> u >> v;
	int ans=MAX;
	dist1[1]=0, distu[u]=0, distv[v]=0;
	priority_queue<pair<int,int>> pq;
	pq.push({0,1});
	while(!pq.empty()){
		int cost = -pq.top().first, u=pq.top().second; pq.pop();
		for(pair<int,int> next: adj[u]) {
			if(dist1[next.first]==-1||cost+next.second<dist1[next.first]) {
				dist1[next.first]=cost+next.second;
				pq.push({-(cost+next.second), next.first});
			}
		}
	}
	pq.push({0,u});
	while(!pq.empty()){
		int cost = -pq.top().first, u=pq.top().second; pq.pop();
		for(pair<int,int> next: adj[u]) {
			if(distu[next.first]==-1||cost+next.second<distu[next.first]) {
				distu[next.first]=cost+next.second;
				pq.push({-(cost+next.second), next.first});
			}
		}
	}
	pq.push({0,v});
	while(!pq.empty()){
		int cost = -pq.top().first, u=pq.top().second; pq.pop();
		for(pair<int,int> next: adj[u]) {
			if(distv[next.first]==-1||cost+next.second<distv[next.first]) {
				distv[next.first]=cost+next.second;
				pq.push({-(cost+next.second), next.first});
			}
		}
	}
	if(dist1[u]!=-1 && distu[v] != -1 && distv[n]!=-1) ans=min(ans,dist1[u]+distu[v]+distv[n]);
	if(dist1[v]!=-1 && distv[u] != -1 && distu[n]!=-1) ans=min(ans,dist1[v]+distv[u]+distu[n]);
	cout << (ans==MAX?-1:ans) << '\n';
}
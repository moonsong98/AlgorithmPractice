#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;
const ll M = 1e10;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int V, E, s; cin >> V >> E >> s;
    priority_queue<P> pq;
    vector<vector<P> > adj(V+1);    
    vector<ll> dist(V+1, M); dist[s] = 0;
    for(int i=0; i<E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    pq.push({0, s});
    while(!pq.empty()) {
        ll d = -pq.top().first, u = pq.top().second; pq.pop();
        if(d > dist[u]) continue;
        for(P p: adj[u]) {
            ll v = p.first, w = p.second;
            if(dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                pq.push({-dist[u]+w, v});
            }
        }
    }
    for(int i = 1; i <= V; ++i)
        if(dist[i] == M) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
}

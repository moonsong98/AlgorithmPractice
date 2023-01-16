#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const ll M = 1e10;

void dijkstra(int s, vector<ll>& dist, vector<vector<P> > adj) {
    dist[s] = 0;
    priority_queue<P> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        int u = pq.top().second, d = -pq.top().first; pq.pop();
        if(d > dist[u]) continue;
        for(P p: adj[u]) {
            int v = p.first, w = p.second;
            if(dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int V, E; cin >> V >> E;
    vector<vector<P> > adj(V+1);
    for(int i=0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int s1, s2;
    cin >> s1 >> s2;
    vector<ll> dist1(V+1, M), dist2(V+1, M);
    dijkstra(s1, dist1, adj);
    dijkstra(s2, dist2, adj);
    ll dM = M, lM = M, ans = -1;
    for(int i=1; i<=V; ++i) {
        if(i == s1 || i == s2) continue;
        if(dist1[i] + dist2[i] < lM)
            lM = dist1[i] + dist2[i];
    }
    for(int i=1; i<=V; ++i) {
        if(i == s1 || i == s2) continue;
        if(dist1[i]+dist2[i] > lM) continue;
        if(dist1[i] > dist2[i]) continue;
        if(dist1[i] < dM) {
           dM = dist1[i];
           ans = i;
        }
    }
    cout << ans << '\n';
}

#include<bits/stdc++.h>
using namespace std;

const int INF=1e12;
typedef long long ll;
typedef pair<ll,ll> pii;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int V, E;    
    cin >> V >> E;
    vector<vector<pii> > adj(V+1);
    for(int i=0; i<E; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    bool updated=false;
    vector<ll> dist(V+1, INF);
    dist[1]=0;
    for(int t=0; t<V; ++t) {
        updated=false;
        for(int u=1; u<=V; ++u) {
            if(dist[u]==INF) continue;
            for(auto p: adj[u]) {
                int v=p.first; ll w=p.second;
                if(dist[u]+w<dist[v]) {
                    dist[v]=dist[u]+w;
                    updated=true;
                }
            }
        }
        if(!updated) break;
    }
    if(updated) cout << -1 << '\n';
    else {
        for(int i=2; i<=V; ++i) {
            if(dist[i]==INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }
}

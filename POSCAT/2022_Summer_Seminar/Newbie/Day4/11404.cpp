#include<bits/stdc++.h>
using namespace std;

const int INF=1e9+7;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int> >adj(n+1, vector<int>(n+1, INF));
    for(int i=0; i<=n; ++i) adj[i][i]=0;
    for(int i=0; i<m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v]=min(adj[u][v], w);
    }
    for(int k=1; k<=n; ++k) 
        for(int u=1; u<=n; ++u) {
            if(adj[u][k]==INF) continue;
            for(int v=1; v<=n; ++v)
                adj[u][v]=min(adj[u][v], adj[u][k]+adj[k][v]);
        }
    for(int u=1; u<=n; ++u) {
        for(int v=1; v<=n; ++v)
            cout << (adj[u][v]==INF?0:adj[u][v]) << ' ';
        cout <<'\n';
    }
}

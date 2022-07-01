#include<bits/stdc++.h>
#include <cmath>
using namespace std;

int main(void) {
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int> > adj(n+1);
    vector<int> visited(n+1, 0);
    int order=1;
    for(int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; ++i)
        sort(adj[i].begin(), adj[i].end());
    queue<int> q;
    q.push(r);
    visited[r]=order++;
    while(!q.empty()) {
        int u=q.front(); q.pop();
        for(int v: adj[u])
            if(!visited[v]) {
                visited[v]=order++;
                q.push(v);
            }
    }
    for(int i=1; i<=n; ++i)
        cout << visited[i] << '\n';
}

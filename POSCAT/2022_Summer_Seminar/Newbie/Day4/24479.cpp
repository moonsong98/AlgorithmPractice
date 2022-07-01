#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int> visited;
int order=1;

void dfs(int u) {
    visited[u]=order++;
    for(int v: adj[u]) {
        if(visited[v]) continue;
        dfs(v);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, r;
    cin >> n >> m >> r;
    adj=vector<vector<int> >(n+1);
    visited=vector<int>(n+1, 0);
    for(int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; ++i) 
        sort(adj[i].begin(), adj[i].end());
    dfs(r);
    for(int i=1; i<=n; ++i) cout << visited[i] << '\n';
}


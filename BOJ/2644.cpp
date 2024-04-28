#include<iostream>
#include<vector>

using namespace std;

int a, b;
vector<vector<int>> adj;
vector<int> numFar;

void dfs(int u) {
    for(int v: adj[u]) 
        if(numFar[v]==-1) {
            numFar[v]=numFar[u]+1;
            dfs(v);
        }
}

int main(void) {
    int n, m;
    cin >> n >> a >> b;
    adj=vector<vector<int>>(n+1, vector<int>());
    numFar=vector<int>(n+1, -1);
    cin >> m;
    for(int i=0; i<m; ++i) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    numFar[a]=0;
    dfs(a);
    cout << numFar[b] << '\n';
}

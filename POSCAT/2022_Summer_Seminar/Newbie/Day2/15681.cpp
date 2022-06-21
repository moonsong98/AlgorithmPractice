#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int> dp;

int dfs(int u, int p) {
    int& ret=dp[u];
    for(int v: adj[u]) {
        if(v==p) continue;
        ret+=dfs(v, u);
    }
    return ++ret;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, r, q;
    cin >> n >> r >> q;
    adj=vector<vector<int> > (n+1);
    dp=vector<int>(n+1, 0);
    for(int i=0; i+1<n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(r, -1);
    while(q--) {
        int u; cin >> u;
        cout << dp[u] << '\n';
    }
}

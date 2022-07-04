#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> cache;
vector<vector<int>> adj;
vector<int> depth;
void dfs(int u, int p) {
    for(int v: adj[u])
        if(v!=p) {
            cache[v][0]=u;
            depth[v]=depth[u]+1;
            dfs(v, u);
        }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, Q; cin >> N;
    adj=vector<vector<int>>(N+1);
    cache=vector<vector<int>>(N+1, vector<int>(20, -1));
    depth=vector<int>(N+1, 0);
    for(int i=0; i<N-1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    for(int j=1; j<20; ++j)
        for(int u=2; u<=N; ++u)
            if(depth[u]>=(1<<j))
                cache[u][j]=cache[cache[u][j-1]][j-1];
    cin >> Q;
    while(Q--){
        int u, v; cin >> u >> v;
        if(depth[u]<depth[v]) {
            int t=u; u=v; v=t;
        }
        int up=depth[u]-depth[v], cnt=0;
        while(up) {
            if(up&1) u=cache[u][cnt];
            ++cnt;
            up>>=1;
        }
        for(int i=19; i>=0; --i) {
            if(cache[u][i]!=cache[v][i]) {
                u=cache[u][i];
                v=cache[v][i];
            }
        }
        cout << (u==v?u:cache[u][0]) << '\n';
    }
}

#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
const int INF=1e9+7;

vector<int> depth;
vector<vector<pii>> adj;
vector<vector<int>> minWeight, maxWeight, anc;

void dfs(int u, int p) {
    for(auto a: adj[u]) {
        int v=a.first, w=a.second;
        if(v!=p) {
            depth[v]=depth[u]+1;
            anc[v][0]=u;
            minWeight[v][0]=w;
            maxWeight[v][0]=w;
            dfs(v, u);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    depth=vector<int>(N+1);
    adj=vector<vector<pii>>(N+1);
    anc=vector<vector<int>>(N+1, vector<int>(20));
    minWeight=vector<vector<int>>(N+1, vector<int>(20));
    maxWeight=vector<vector<int>>(N+1, vector<int>(20));
    for(int i=0; i+1<N; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, -1);
    for(int j=1; j<20; ++j) {
        for(int u=2; u<=N; ++u) {
            if(depth[u]<(1<<j)) continue;
            anc[u][j]=anc[anc[u][j-1]][j-1];
            minWeight[u][j]=min(minWeight[u][j-1],minWeight[anc[u][j-1]][j-1]);
            maxWeight[u][j]=max(maxWeight[u][j-1],maxWeight[anc[u][j-1]][j-1]);
        }
    }
    int Q; cin >> Q;
    while(Q--) {
        int u, v; cin >> u >> v;
        if(depth[u]<depth[v]) {
            int t=u; u=v; v=t;
        }
        int minLen=INF, maxLen=-1;
        int diff=depth[u]-depth[v], cnt=0;
        while(diff) {
            if(diff&1) {
                minLen=min(minLen, minWeight[u][cnt]);
                maxLen=max(maxLen, maxWeight[u][cnt]);
                u=anc[u][cnt];
            }
            ++cnt;
            diff>>=1;
        }
        for(int i=19; i>=0; --i) {
            if(anc[u][i]!=anc[v][i]) {
                minLen=min({minLen, minWeight[u][i], minWeight[v][i]});
                maxLen=max({maxLen, maxWeight[u][i], maxWeight[v][i]});
                u=anc[u][i];
                v=anc[v][i];
            }
        }
        if(u!=v)
            cout << min({minLen, minWeight[u][0], minWeight[v][0]}) << ' '
                << max({maxLen, maxWeight[u][0], maxWeight[v][0]}) << '\n';
        else cout << minLen << ' ' << maxLen << '\n';
    }
}

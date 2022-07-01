#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int INF=1e9+7;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int V, E; cin >> V >> E;
    vector<vector<pii> > adj(V+1);
    vector<bool> isHome(V+1, true);
    for(int i=0; i<E; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int m, x, s, y;
    cin >> m >> x;
    vector<int> M(m), distM(V+1, INF), distS(V+1, INF); 
    distM[0]=0, distS[0]=0;
    priority_queue<pii> pq;
    for(int i=0; i<m; ++i) {
        cin >> M[i];
        adj[0].push_back({M[i],0});
        isHome[M[i]]=false;
    }
    pq.push({0, 0});
    while(!pq.empty()) {
        int u=pq.top().second, cur=-pq.top().first;
        pq.pop();
        if(distM[u]>cur) continue;
        for(auto p: adj[u]) {
            int v=p.first, w=p.second;
            if(cur+w<distM[v]) {
                distM[v]=cur+w;
                pq.push({-distM[v], v});
            }
        }
    }
    adj[0].clear();
    cin >> s >> y;
    vector<int> S(s);
    for(int i=0; i<s; ++i) {
        cin >> S[i];
        adj[0].push_back({S[i], 0});
        isHome[S[i]]=false;
    }
    pq.push({0, 0});
    while(!pq.empty()) {
        int u=pq.top().second, cur=-pq.top().first;
        pq.pop();
        if(distS[u]>cur) continue;
        for(auto p: adj[u]) {
            int v=p.first, w=p.second;
            if(cur+w<distS[v]) {
                distS[v]=cur+w;
                pq.push({-distS[v], v});
            }
        }
    }
    int ans=INF;
    for(int i=1; i<=V; ++i) {
        if(isHome[i]==false) continue;
        if(distM[i]<=x&&distS[i]<=y)
            ans=min(ans, distM[i]+distS[i]);
    }
    cout << (ans==INF?-1:ans) << '\n';
}


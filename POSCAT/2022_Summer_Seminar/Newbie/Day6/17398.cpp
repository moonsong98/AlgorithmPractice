#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<int> p, sz;

int find(int u) {
    if(p[u]==u) return u;
    return p[u]=find(p[u]);
}

ll merge(int u, int v) {
    u=find(u), v=find(v);
    if(u==v) return 0;
    ll ret=sz[u]*sz[v];
    p[v]=u, sz[u]+=sz[v];
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, M, Q;
    cin >> N >> M >> Q;
    p=vector<int>(N+1); for(int i=1; i<=N; ++i) p[i]=i;
    sz=vector<int>(N+1, 1);
    vector<pii> edges(M+1);
    vector<int> order;
    vector<bool> connected(M+1, true);
    for(int i=1; i<=M; ++i) cin >> edges[i].first >> edges[i].second;
    for(int i=0; i<Q; ++i) {
        int q; cin >> q;
        order.push_back(q);
        connected[q]=false;
    }
    for(int i=1; i<=M; ++i)
        if(connected[i])
            merge(edges[i].first, edges[i].second);
    reverse(order.begin(), order.end());
    ll ans=0;
    for(int i=0; i<Q; ++i)
        ans+=merge(edges[order[i]].first, edges[order[i]].second);
    cout << ans << '\n';
}

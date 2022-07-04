#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct EDGE {
    int u, v;
    ll w;
};

bool cmp(const EDGE& A, const EDGE& B) {
    return A.w<B.w;
}

vector<int> p;

int find(int u) {
    if(p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool merge(int u, int v) {
    u=find(u), v=find(v);
    if(u==v) return false;
    p[v]=u;
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int V, E; cin >> V >> E;
    vector<EDGE> edges(E);
    p=vector<int>(V+1); for(int i=1; i<=V; ++i) p[i]=i;
    for(int i=0; i<E; ++i)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges.begin(), edges.end(), cmp);
    ll ans=0;
    for(int i=0; i<E; ++i)
        if(merge(edges[i].u, edges[i].v))
            ans+=edges[i].w;
    cout << ans << '\n';
}

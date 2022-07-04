#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;

struct Edge{
    int u, v;
    ll w;
};

vector<int> p, depth;
vector<vector<pii>> adj;
vector<vector<int>> anc;
vector<vector<ll>> maxWeight;
bool cmp(const Edge& a, const Edge &b) {
    return a.w < b.w;
}
int find(int u) {
    if(u==p[u]) return u;
    return p[u]=find(p[u]);
}
bool merge(int u, int v) {
    u=find(u), v=find(v);
    if(u==v) return false;
    p[v]=u; return true;
} 

void dfs(int u, int p) {
    for(auto a: adj[u]) {
        int v=a.first; ll w=a.second;
        if(v!=p) {
            depth[v]=depth[u]+1;
            anc[v][0]=u;
            maxWeight[v][0]=w;
            dfs(v, u);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, M; cin >> N >> M;
    p=vector<int>(N+1); for(int i=1; i<=N; ++i) p[i]=i;
    depth=vector<int>(N+1);
    adj=vector<vector<pii>>(N+1);
    anc=vector<vector<int>>(N+1, vector<int>(20));
    maxWeight=vector<vector<ll>>(N+1, vector<ll>(20));
    vector<Edge> cand, list;
    for(int i=0; i<M; ++i) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        cand.push_back(e);
        list.push_back(e);
    }
    ll mstSum=0;
    sort(cand.begin(), cand.end(), cmp);
    for(int i=0; i<M; ++i) {
        int u=cand[i].u, v=cand[i].v;
        ll w=cand[i].w;
        if(merge(u, v)) {
            mstSum+=w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
    }
    dfs(1, -1);
    for(int j=1; j<=20; ++j) {
        for(int u=2; u<=N; ++u) {
            if(depth[u]<(1<<j)) continue;
            anc[u][j]=anc[anc[u][j-1]][j-1];
            maxWeight[u][j]=max(maxWeight[u][j-1],maxWeight[anc[u][j-1]][j-1]);
        }
    }
    for(int i=0; i<M; ++i) {
        int u=list[i].u, v=list[i].v, w=list[i].w;
        ll maxLen=-1;
        if(depth[u]<depth[v]) {
            int t=u; u=v; v=t;
        }
        int diff=depth[u]-depth[v], cnt=0;
        while(diff) {
            if(diff&1) {
                maxLen=max({maxLen, maxWeight[u][cnt]});
                u=anc[u][cnt];
            }
            ++cnt;
            diff>>=1;
        }
        for(int j=19; j>=0; --j){
            if(anc[u][j]!=anc[v][j]) {
                maxLen=max({maxLen, maxWeight[u][j], maxWeight[v][j]});
                u=anc[u][j];
                v=anc[v][j];
            }
        }
        if(u!=v)
            maxLen=max({maxLen, maxWeight[u][0], maxWeight[v][0]});
        cout << mstSum+w-maxLen << '\n';
    }
}

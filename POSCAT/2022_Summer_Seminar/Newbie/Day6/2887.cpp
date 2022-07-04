#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;

struct edge {
    int u, v;
    ll w;
};

vector<int> p;
vector<edge> cand;
vector<pii> xs, ys, zs;
int find(int u) {
    if(u==p[u]) return u;
    return p[u]=find(p[u]);
}
bool merge(int u, int v) {
    u=find(u), v=find(v);
    if(u==v) return false;
    p[v]=u; return true;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    p=vector<int>(N+1); for(int i=1; i<=N; ++i) p[i]=i;
    for(int i=0; i<N; ++i) {
        ll x, y, z;
        cin >> x >> y >> z;
        xs.push_back({x, i});
        ys.push_back({y, i});
        zs.push_back({z, i});
    }
    sort(all(xs)); sort(all(ys)); sort(all(zs));
    for(int i=0; i+1<N; ++i) {
        edge e;
        e.w=xs[i+1].first-xs[i].first; e.u=xs[i+1].second, e.v=xs[i].second;
        cand.push_back(e);
        e.w=ys[i+1].first-ys[i].first; e.u=ys[i+1].second, e.v=ys[i].second;
        cand.push_back(e);
        e.w=zs[i+1].first-zs[i].first; e.u=zs[i+1].second, e.v=zs[i].second;
        cand.push_back(e);
    }
    sort(all(cand), [&](auto a, auto b)->bool{
            return a.w<b.w;
            });
    ll ans=0;
    for(int i=0; i<sz(cand); ++i) {
        int u=cand[i].u, v=cand[i].v, w=cand[i].w;
        if(merge(u,v))
            ans+=w;
    }
    cout << ans << '\n';
}

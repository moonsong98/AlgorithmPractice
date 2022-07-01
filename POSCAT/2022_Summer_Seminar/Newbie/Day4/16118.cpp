#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF=1e12;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<vector<pair<int, ll> > > adj(N+1);
    for(int i=0; i<M; ++i) {
        int u, v, w; cin >> u >> v >> w;
        w*=2;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<ll> dist1(N+1, INF);
    dist1[1]=0;
    priority_queue<pair<ll, int> > pq1;
    pq1.push({0, 1});
    while(!pq1.empty()) {
        int u=pq1.top().second; ll cur=-pq1.top().first; pq1.pop();
        if(dist1[u]<cur) continue;
        for(auto p: adj[u]) {
            int v=p.first, w=p.second;
            if(cur+w<dist1[v]) {
                dist1[v]=cur+w;
                pq1.push({-dist1[v], v});
            }
        }
    }

    vector<ll> dist2(N+1, INF);
    vector<ll> dist3(N+1, INF);
    priority_queue<pair<pair<ll, int>, int> > pq2;
    pq2.push({{0, -2}, 1});
    while(!pq2.empty()) {
        int u=pq2.top().second, mul=-pq2.top().first.second;
        ll cur=-pq2.top().first.first; pq2.pop();
        if(mul==2&&dist3[u]<cur) continue; 
        if(mul==1&&dist2[u]<cur) continue;
        for(auto p: adj[u]) {
            int v=p.first, w=p.second;
            if(mul==2) {
                int next=cur+w/2;
                if(next<dist2[v]) {
                    dist2[v]=next;
                    int nextMul=1;
                    pq2.push({{-dist2[v],-nextMul},v});
                }
            }
            else {
                int next=cur+w*2;
                if(next<dist3[v]) {
                    dist3[v]=next;
                    int nextMul=2;
                    pq2.push({{-dist3[v],-nextMul},v});
                }
            }
        }
    }
    int cnt=0;
    for(int i=2; i<=N; ++i)
        if(dist1[i]<dist2[i]&&dist1[i]<dist3[i])
            ++cnt;
    cout << cnt << '\n';
}

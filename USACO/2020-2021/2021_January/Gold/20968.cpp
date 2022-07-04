#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, K; cin >> N >> K;
    vector<int> compNum(N); 
    vector<vector<int>> comps(K+1);
    vector<vector<int>> adj(N);
    for(int i=0; i<N; ++i) {
        cin >> compNum[i];
        comps[compNum[i]].push_back(i);
    }
    for(int i=1; i<=K; ++i) for(int j=1; j<=K; ++j) {
        char ch; cin >> ch;
        if(comps[j].empty()) continue;
        if(ch-'0') {
            for(int u:comps[i]) {
                auto lb=lower_bound(comps[j].begin(), comps[j].end(), u);
                if(lb==comps[j].begin()) {
                    if(*lb!=u)
                        adj[u].push_back(*lb);
                }
                else if(lb==comps[j].end())
                    adj[u].push_back(*(lb-1));
                else {
                    if(*lb==u) {
                        adj[u].push_back(*(lb-1));
                        if(comps[j].end()-lb>1) 
                            adj[u].push_back(*(lb+1));
                    }
                    else {
                        adj[u].push_back(*(lb-1));
                        adj[u].push_back(*lb);
                    }
                }
                if(u!=N-1&&j==compNum[N-1]) adj[u].push_back(N-1);
            }
        }
    }
    vector<long long> dist(N, LLONG_MAX);
    dist[0]=0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        ll cur=-pq.top().first; int u=pq.top().second; pq.pop();
        if(dist[u]<cur) continue;
        if(u==N-1) break;
        for(int v: adj[u]) {
            ll newDist=(ll)abs(u-v)+cur;
            if(newDist<dist[v]) {
                dist[v]=newDist;
                pq.push({-newDist, v});
            }
        }
    }
    cout << (dist[N-1]==LLONG_MAX?-1:dist[N-1]) << '\n';
}

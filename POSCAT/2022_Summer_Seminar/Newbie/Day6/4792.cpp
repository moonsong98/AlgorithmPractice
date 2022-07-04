#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v;
};

vector<Edge> Blues, Reds;
vector<int> p;

int find(int u) {
    if(u==p[u]) return u;
    return p[u]=find(p[u]);
}

bool merge(int u, int v) {
    u=find(u), v=find(v);
    if(u==v) return false;
    p[v]=u; return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k;
    while(true) {
        cin >> n >> m >> k;
        if(!n&&!m&&!k) return 0;
        int minBlue=0, maxBlue=0;
        p=vector<int>(n+1); Reds.clear(); Blues.clear();
        for(int i=0; i<m; ++i) {
            Edge e;
            char c;
            cin >> c >> e.u >> e.v;
            c=='B'?Blues.push_back(e):Reds.push_back(e);
        }
        for(int i=1; i<=n; ++i) p[i]=i;
        for(auto e: Reds) 
            merge(e.u, e.v);
        for(auto e: Blues)
            if(merge(e.u, e.v))
                minBlue++;
        for(int i=1; i<=n; ++i) p[i]=i;
        for(auto e: Blues)
            if(merge(e.u, e.v))
                maxBlue++;
        for(auto e: Reds) 
            merge(e.u, e.v);
        cout << (minBlue<=k&&k<=maxBlue) << '\n';
    }
}

#include<iostream>
#include<vector>

using namespace std;

vector<int> parent;
vector<int> r;

int find(int u) {
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}

void merge(int u, int v) {
    u=find(u), v=find(v);
    if(u==v) return;
    if(r[u]>r[v]) {
        int t=u; u=v; v=t;
    }
    if(r[u]==r[v]) r[v]++;
    parent[u]=v;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for(int i=0; i<=n; ++i) {
        parent.push_back(i);
        r.push_back(1);
    }
    while(m--) {
        int op, a, b; cin >> op >> a >> b;
        if(op) cout << (find(a)==find(b) ? "YES" : "NO") << '\n';
        else merge(a, b);
    }
}

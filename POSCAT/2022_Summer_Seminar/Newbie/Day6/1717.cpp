#include<bits/stdc++.h>
using namespace std;

vector<int> p;
int find(int u) {
    if(p[u]==u)  return u;
    return p[u]=find(p[u]);
}

void merge(int u, int v) {
    u=find(u), v=find(v);
    if(u==v) return;
    p[v]=u;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, q; cin >> n >> q;
    p=vector<int>(n+1);
    for(int i=0; i<=n; ++i) p[i]=i;
    for(int i=0; i<q; ++i) {
        int cmd, u, v;
        cin >> cmd >> u >> v;
        if(cmd) cout << (find(u)==find(v)?"YES":"NO")  << '\n';
        else merge(u, v);
    }
}

#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int> > adj(n+1);
        for(int i=0; i<m; ++i) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> groupNum(n+1, -1);
        bool invalid=false;
        for(int i=1; i<=n; ++i) {
            if(groupNum[i]==-1) {
                queue<int> q;
                groupNum[i]=0;
                q.push(i);
                while(!q.empty()) {
                    int u=q.front(); q.pop();
                    for(int v: adj[u]) {
                        if(groupNum[v]==groupNum[u]) {
                            invalid=true;
                            break;
                        }
                        else if(groupNum[v]==-1) {
                            groupNum[v]=!groupNum[u];
                            q.push(v);
                        }
                    }
                    if(invalid) break;
                }
            }
            if(invalid) break;
        }
        cout << (invalid?"NO":"YES") << '\n';
    }
}

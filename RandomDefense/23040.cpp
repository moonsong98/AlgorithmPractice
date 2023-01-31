#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vector<vector<int>> adj(N+1);
    vector<bool> isRed(N+1);
    vector<int> componentNum(N+1, -1), componentSize;
    queue<int> q;
    for(int i=0; i+1<N; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=N; ++i) {
        char c; cin >> c;
        isRed[i] = (c == 'R');
    }
    for(int i=1; i<=N; ++i) {
        if(!isRed[i] || componentNum[i] > -1)  continue;
        int cmpNum = componentSize.size();
        componentSize.push_back(1);
        q.push(i);
        componentNum[i]=cmpNum;
        while(!q.empty()) {
            int u=q.front(); q.pop();
            for(int v: adj[u]) {
                if(isRed[v]&&componentNum[v]==-1) {
                    q.push(v);
                    componentNum[v] = cmpNum;
                    componentSize[cmpNum]++;
                }
            }
        }
    }
    long long ans = 0;
    for(int i=1; i<=N; ++i) {
        if(isRed[i]) continue;
        for(int v: adj[i])
            if(isRed[v])
                ans += (long long)componentSize[componentNum[v]];
    }
    cout << ans << '\n';
}

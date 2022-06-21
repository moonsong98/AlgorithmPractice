#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int> >adj(N, vector<int>(N));
    vector<vector<int> >dp(N, vector<int>(1<<N, 1e9));
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin >> adj[i][j];
    dp[0][1]=0;
    for(int visited=0; visited<(1<<N); ++visited) {
        for(int cur=1; cur<N; ++cur) {
            if(visited&(1<<cur)) continue;
            for(int prev=0; prev<N; ++prev) {
                if(adj[prev][cur]==0||(visited&(1<<prev))==0) continue;
                dp[cur][visited|(1<<cur)]=min(dp[cur][visited|(1<<cur)], dp[prev][visited]+adj[prev][cur]);
            }
        }
    }
    int ans=1e9;
    for(int i=1; i<N; ++i) {
        if(adj[i][0]==0) continue;
        ans=min(ans, dp[i][(1<<N)-1]+adj[i][0]);
    }
    cout << ans << '\n';
}

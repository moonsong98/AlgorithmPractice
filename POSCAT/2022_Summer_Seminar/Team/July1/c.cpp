#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<string> board(n);
    vector<vector<ll> > dp(n, vector<ll>(m,1));
    ll ans=0;
    for(int i=0; i<n; ++i)
        cin >> board[i];
    for(int i=1; i<n; ++i) for(int j=1; j<m; ++j) {
        if(board[i][j]!=board[i][j-1]&&board[i][j]!=board[i-1][j]&&board[i][j]==board[i-1][j-1])
            dp[i][j]=min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
    }
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
        ans+=dp[i][j];
    cout << ans << '\n';
}

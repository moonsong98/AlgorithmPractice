#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    int ans=-1e9;
    vector<int> v(n+1);
    vector<int> dp(n+1, -1e9);
    for(int i=1; i<=n; ++i) cin >> v[i];
    for(int i=1; i<=n; ++i) {
        dp[i]=dp[i-1]>0?dp[i-1]+v[i]:v[i];
        ans=max(ans, dp[i]);
    }
    cout << ans << '\n';
}


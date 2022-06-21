#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    vector<int> v(n+1);
    for(int i=1; i<=n; ++i) cin >>v[i];
    if(n<=2) {
        int ans=0;
        for(int i=1; i<=n; ++i) ans+=v[i];
        cout << ans << '\n';
        return 0;
    }
    vector<int> dp(n+1, 0);
    dp[1]=v[1]; dp[2]=v[1]+v[2];
    for(int i=3; i<=n; ++i) 
        dp[i] = max(dp[i-3]+v[i-1]+v[i], dp[i-2]+v[i]);
    cout << dp[n] << '\n';
}

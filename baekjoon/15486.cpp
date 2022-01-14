#include<iostream>
#include<vector>

using namespace std;

int main(void) {
    int n; cin >> n;
    vector<int> t(n+1), p(n+1), dp(n+2,0);
    for(int i=1; i<=n; ++i) cin >> t[i] >> p[i];
    for(int i=n; i>=1; --i)  {
        dp[i]=dp[i+1];
        if(i+t[i]<=n+1)
            dp[i] = max(dp[i], dp[i+t[i]]+p[i]);
    }
    
    cout << dp[1] << '\n';
}

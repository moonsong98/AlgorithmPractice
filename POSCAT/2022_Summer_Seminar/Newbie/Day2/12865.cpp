#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), w(n);
    vector<int> dp(k+1, 0);
    for(int i=0; i<n; ++i) cin >> w[i] >> v[i];
    for(int i=0; i<n; ++i)
        for(int j=k; j-w[i]>=0; --j)
            dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
    cout << dp[k] << '\n';
}

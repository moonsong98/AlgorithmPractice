#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        long long n, m; cin >> n >> m;
        long long ans=m*(m+1)/2+n*(n+1)*m/2-m;
        cout << ans << '\n';
    }
}

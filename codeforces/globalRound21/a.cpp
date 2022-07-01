#include<bits/stdc++.h>
#include <cstddef>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, z, ans=-1; cin >> n >> z;
        for(int i=0; i<n; ++i) {
            int a; cin >> a;
            ans=max(ans, a|z);
        }
        cout << ans << '\n';
    }
}

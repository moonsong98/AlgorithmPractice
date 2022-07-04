#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        ll n, k; cin >> n >> k;
        k=min(k, n);
        cout << 4*(k+1)*(n+n-k)/2 << '\n';
    }
}

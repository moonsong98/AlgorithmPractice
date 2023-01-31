#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, Q, ans = 0; cin >> N >> Q;
    while(Q--) {
        int q, l, r;
        cin >> q >> l >> r;
        if(q==1) ans^=1;
        else {
            int m = (r - l) % 4;
            if(m == 1 || m == 2) ans ^= 1;
        }
        cout << ans << '\n';
    }
}

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for(int i = 1; i <= t; ++i) {
        ll n, m, ans = 0; cin >> n >> m;
        vector<int> times(n);
        for(int &a: times)
            cin >> a;
        ll l = 0, r = (ll)*max_element(times.begin(), times.end()) * m;
        while(l <= r) {
            ll mid = l + (r-l)/2, cnt = 0;
            for(int a: times)
                cnt += mid / a;
            if(cnt >= m) {
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        cout << '#' <<  i << ' ' << ans << '\n';
    }
}

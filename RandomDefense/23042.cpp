#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vector<ll> nums(N), cnt(30, 0);

    for(int i=0; i<N; ++i) {
        ll a, cur = 0; cin >> a;
        while(a > 0) {
            if(a%2)
                cnt[cur]++;
            a >>= 1;
            cur++;
        }
    }

    for(int i=0; i<30; ++i)
        for(int j = 0; j < cnt[i]; ++j)
            nums[j] |= (1<<i);

    const ll mod = 1e9 + 7;
    auto mul = [](ll a, ll b) -> ll {
        return ((a%mod)*(b%mod))%mod;
    };

    ll ans = 1;
    for(ll a: nums) {
        ans = mul(ans, a);
    }
    cout << ans << '\n';
}
/*
#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vector<int> nums(N); for(int &a: nums) cin >> a;
    sort(nums.begin(), nums.end());
    for(int i=0; i+1<N; ++i) {
        int tmp1 = nums[i], tmp2 = nums[i+1];
        nums[i] = tmp1 & tmp2;
        nums[i+1] = (tmp1&tmp2) | (tmp1^tmp2);
    }
    const int mod = 1e9 + 7;
    auto mul = [](int a, int b) -> int {
        return ((a%mod)*(b%mod))%mod;
    };
    int ans = 1;
    for(int a: nums)
        ans = mul(ans, a);
    cout << ans << '\n';
}
*/

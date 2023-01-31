#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll n, k; cin >> n >> k;
    vector<ll> A(n); for(ll &a: A) cin >> a;
    
    ll l=1, r=2*1e10, ans;

    while(l<=r) {
        ll mid = l+(r-l)/2, sum = mid*(mid+1)/2, valid=false;
        for(int i=0; i+1<n; ++i) {
            if(A[i+1] - A[i] < mid) sum += (2*mid - (A[i+1]-A[i]) + 1) * (A[i+1]-A[i]) / 2;
            else sum += mid*(mid+1)/2;
            if(sum >= k) {
                valid = true;
                break;
            }
        }
        if(valid) {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << '\n';
}

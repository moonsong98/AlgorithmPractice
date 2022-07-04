#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;

int main(void) {
    int n, ans=0;
    ll x;
    cin >> n >> x;
    vector<ll> v;
    for(int i=0; i<n; ++i) {
        ll num; cin >> num;
        if(num==x) ++ans;
        else v.push_back(num);
    }
    sort(v.begin(), v.end());
    int l=0, r=sz(v)-1, cnt=0;
    while(l<r) {
        while(l<sz(v)&&2*(v[l]+v[r])<x) ++l;
        if(l>=sz(v)) break;
        ++cnt;
        ++l; --r;
    }
    cout << ans+cnt+(sz(v)-cnt*2)/3 << '\n';
}


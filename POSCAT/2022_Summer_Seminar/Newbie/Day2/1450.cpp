#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
typedef long long ll;

int main(void) {
    int n, c; cin >> n >> c;
    int half=n/2;
    vector<int> w(n);

    for(int &num: w) cin >> num;
    vector<ll> f(1<<half, 0), s(1<<(n-half), 0);
    for(int i=0; i<half; ++i)
        for(int j=0; j<(1<<half); ++j)
            if(j&(1<<i)) f[j]+=w[i];
    for(int i=0; i<n-half; ++i) {
        for(int j=0; j<(1<<(n-half)); ++j)
            if(j&(1<<i)) s[j]+=w[half+i];
    }
    sort(all(s));
    int ans=0;
    for(ll a: f) {
        auto ub=upper_bound(all(s), c-a);
        ans+=ub-s.begin();
    }
    cout << ans << '\n';
}

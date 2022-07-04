#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    ll n, k, s=-1;
    cin >> n >> k;
    vector<ll> v(n); 
    for(int i=0; i<n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=1; i<n; ++i)
        s=max(s, v[0]*i+v[i]*(n-i));
    cout << k/s+(k%s>0) << '\n';
}

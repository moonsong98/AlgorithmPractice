#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		ll n, x;
		cin >> n >> x;
		vector<ll> v(n);
		cin >> v[0];
		ll ans=0, m1=v[0], m2=1, M1=v[0], M2=x;
		for(int i=1; i<n; ++i) {
			cin >> v[i];
			m1=min(v[i], m1);
			M1=max(v[i], M1);
			ans+=abs(v[i]-v[i-1]);
		}
		if(m2<m1)
			ans+=min({(m1-m2)*2, v[0]-m2, v[n-1]-m2});
		if(M2>M1)
			ans+=min({(M2-M1)*2, M2-v[n-1], M2-v[0]});
		cout << ans << '\n';
	}
}

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		ll n, x;
		cin >> n >> x;
		ll start=0;
		vector<ll> v(n);
		ll sum=0;
		for(ll &a: v)
			cin >> a;
		sort(all(v), [](ll a, ll b){return a>b;});
		for(int i=sz(v)-1; i>=0; --i) {
			if(sum+v[i]>x) {
				start=i+1;
				break;
			}
			sum+=v[i];
		}
		ll ans=0, cur=-1;
		for(int i=start; i<n; ++i) {
			ans+=((x-sum)/(n-i)-cur)*(n-i);
			cur=(x-sum)/(n-i);
			sum-=v[i];
		}
		cout << ans << '\n';
	}
}
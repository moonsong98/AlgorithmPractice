#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for(ll &a: v) cin >> a;
	queue<pair<int, ll>> q; // pos, times
	ll sum=0, ans=0, ts=0;
	for(int i=n-1; i>=0; --i) {
		if(!q.empty()) {
			sum-=ts;
			if(q.front().first-k>=i) {
				ts-=q.front().second;
				q.pop();
			}
		}
		if(v[i]<sum) continue;
		ll div;
		if(i+1>=k) div=k;
		else div=i+1;
		ll left=v[i]-sum;
		ll t=left/div, r=left%div;
		if(r) ++t;
		q.push({i, t});
		sum+=div*t;
		ts+=t;
		ans+=t;
	}
	cout << ans << '\n';
}
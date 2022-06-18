#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

vector<int> v;

ll calc(ll num, int lb, int ub, int msb) {
	if(lb==ub||msb==-1) return num^v[lb];
	if(!(v[ub]&(1ull<<msb))||(v[lb]&(1ull<<msb))) return calc(num, lb, ub, msb-1);
	int idx, l=lb, r=ub;
	while(l<=r) {
		int mid=l+(r-l)/2;
		if(v[mid]&(1ull<<msb)) {
			idx=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	if(num&(1ull<<msb))
		return calc(num, lb, idx-1, msb-1);
	return calc(num, idx, ub, msb-1);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	vector<int> arr(n);
	v=vector<int>(n+1, 0);
	for(int i=0; i<n; ++i) {
		cin >> arr[i];
		v[i+1]=v[i]^arr[i];
	}
	sort(v.begin(), v.end());
	for(int a: v) cout << a << ' ';
	cout << '\n';
	int idx, l=1, r=n, msb=0;
	while(v.back()>=(1ull<<(msb+1))) ++msb;
	while(l<=r) {
		int mid=l+(r-l)/2;
		if(v[mid]&(1ull<<(msb))) {
			idx=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	ll ans=0;
	for(int i=idx; i<=n; ++i) {
		ll ret=calc(v[i], 0, idx-1, msb);
		ans=max(ans, ret);
	}
	cout << ans << '\n';
}
#include<iostream>

using namespace std;

typedef long long ll;

int main(void) {
	ll d, n, m, k;
	cin >> d >> n >> m >> k;
	ll maxV=n/d+m/d+k/d, ans=k;
	if(ll r=d-n%d; 0<r&&r<=k) {
		ll v=n/d+m/d+(k-r)/d+1;
		if(maxV<v) {
			maxV=v; ans=k-r;
		}
		else if(maxV==v&&ans<k-r) ans=k-r;
	}
	if(ll r=d-m%d; 0<r&&r<=k) {
		ll v=n/d+m/d+(k-r)/d+1;
		if(maxV<v) {
			maxV=v; ans=k-r;
		}
		else if(maxV==v&&ans<k-r) ans=k-r;
	}
	if(ll r=2*d-n%d-m%d; 0<r&&r<=k) {
		int v=n/d+m/d+(k-r)/d+2;
		if(maxV<v) {
			maxV=v; ans=k-r;
		}
		else if(maxV==v&&ans<k-r) ans=k-r;
	}
	cout << ans << '\n';
}
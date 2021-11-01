#include<iostream>

using namespace std;

typedef long long ll;
const ll MOD=1000000007;

ll mul(const ll& A, const ll& B) {
	return ((A%MOD) * (B%MOD))%MOD;
}

int main(void) {
	int n, k, m=MOD-2;
	ll A=1, B=1, ans=1;
	cin >> n >> k;
	for(ll i=1; i<=n; ++i) A=mul(A, i);
	for(ll i=1; i<=n-k; ++i) B=mul(B, i);
	for(ll i=1; i<=k; ++i) B=mul(B, i);
	
	while(m) {
		if(m%2) ans=mul(ans,B);
		B=mul(B,B);	
		m/=2;
	}
	ans=mul(ans,A);
	cout << ans << '\n';
}
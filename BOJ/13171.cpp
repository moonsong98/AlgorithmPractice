#include<iostream>

using namespace std;

typedef long long ll;
const long long MOD = 1000000007;

ll mul(const ll& a, const ll& b) {
	return ((a%MOD)*(b%MOD))%MOD;
}

int main(void) {
	ll a, x, ans=1;
	cin >> a >> x;
	while(x) {
		if(x&1) ans=mul(ans,a);
		a=mul(a,a);
		x>>=1;
	}
	cout << ans << '\n';
}
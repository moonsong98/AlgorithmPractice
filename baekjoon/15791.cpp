#include<iostream>

using namespace std;
typedef long long ll;

ll factorial[1000001]={1,1,};

const ll MOD=1000000007;

ll mul(const ll& a, const ll& b) {
	return ((a%MOD)*(b%MOD))%MOD;
}

int main(void) {
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; ++i) factorial[i]=mul(factorial[i-1],i);
	ll ans=factorial[n], B=mul(factorial[n-m], factorial[m]), k=MOD - 2;
	while(k) {
		if(k&1) ans=mul(ans,B);
		k>>=1;
		B=mul(B,B);
	}
	cout << ans << '\n';
}
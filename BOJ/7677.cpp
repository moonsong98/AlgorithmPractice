#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
const ll MOD=10000;

matrix operator*(const matrix& A, const matrix& B) {
	ll l=A.size(), m=B.size(), n=B[0].size();
	matrix ret(l, vector<ll>(n,0));
	for(ll i=0; i<l; ++i) for(ll j=0; j<n; ++j) {
		for(ll k=0; k<m; ++k) ret[i][j]+=A[i][k]*B[k][j];
		ret[i][j]%=MOD;
	}
	return ret;
}

int main(void) {
	while(true) {
		ll n;
		cin >> n;
		if(n==-1) break;
		matrix ans={{1},{0}}, A={{1,1},{1,0}};
		while(n) {
			if(n%2) ans=A*ans;
			A=A*A;
			n>>=1;
		}
		cout << ans[1][0] << '\n';
	}
}
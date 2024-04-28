#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

const ll MOD=1000000007;
matrix M;
matrix operator*(const matrix& A, const matrix& B){
	long long n=sz(A), m=sz(B), l=sz(B[0]);
	matrix ret(n,vector<long long>(l,0));
	for(int i=0; i<n; ++i) for(int j=0; j<l; ++j) {
		for(int k=0; k<m; ++k) {
			ret[i][j]+=A[i][k]*B[k][j];
		    ret[i][j]%=MOD;            
        }
	}
	return ret;
}

int main(void) {
	int n, m; cin >> n >> m;
	matrix init(n, vector<ll>(n, 0));
	matrix M(n, vector<ll>(n, 0));
	for(int i=0; i<m; ++i) {
		int u, v; cin >> u >> v;
		M[u-1][v-1]=M[v-1][u-1]=1;
		init[u-1][v-1]=init[v-1][u-1]=1;
	}
	ll D;
	cin >> D;
	--D;
	while(D) {
		if(D%2) init=M*init;
		M=M*M;
		D>>=1;
	}
	cout << init[0][0] << '\n';
}

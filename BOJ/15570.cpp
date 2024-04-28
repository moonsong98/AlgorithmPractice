#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
typedef vector<vector<int>> matrix;

const int MOD=1999;

matrix M, cache;
matrix operator*(const matrix& A, const matrix& B){
	int n=sz(A), m=sz(B), l=sz(B[0]);
	matrix ret(n,vector<int>(l,0));
	for(int i=0; i<n; ++i) for(int j=0; j<l; ++j) {
		for(int k=0; k<m; ++k) {
			ret[i][j]+=A[i][k]*B[k][j];
			ret[i][j]%=MOD;            
		}
	}
	return ret;
}

int main(void) {
	int n;
	long long m;
	cin >> n >> m;
	cache=vector<vector<int>>(n, vector<int>(1, 0));
	M=vector<vector<int>>(n, vector<int>(n, 0));
	if(n==1) {
		cout << 1;
		return 0;
	}
	cache[n-1][0]=1;
	for(int i=n-2; i>=0; --i)
		cache[i][0]=(cache[i+1][0]<<1)%MOD;
	cache[0][0]=(cache[0][0]<<1)%MOD-1;
	if(m<=n)
		cout << cache[n-m][0];
	else {
		for(int i=0; i+1<n; ++i)
			M[i+1][i]=M[0][i]=1;
		M[0][n-1]=(cache[1][0]*2)%MOD;
		long long D=m-n;
		while(D) {
			if(D&1) cache=M*cache;
			M=M*M;
			D>>=1;
		}
		cout << cache[0][0];
	}
}

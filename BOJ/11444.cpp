#include<iostream>
#include<vector>

using namespace std;

typedef vector<vector<long long>> matrix;
const long long MOD=1000000007;

matrix operator*(const matrix& A, const matrix& B){
	long long n=A.size(), m=B.size(), l=B[0].size();
	matrix ret(n,vector<long long>(l,0));
	for(int i=0; i<n; ++i) for(int j=0; j<l; ++j) {
		for(int k=0; k<m; ++k) 
			ret[i][j]+=A[i][k]*B[k][j];
		ret[i][j]%=MOD;
	}
	return ret;
}

int main(void) {
	matrix ans={{1},{0}};
	matrix A={{1,1},{1,0}};	
	long long n;
	cin >> n;
	while(n) {
		if(n%2) ans=A*ans;
		A=A*A;
		n>>=1;
	}
	cout << ans[1][0] << '\n';
}

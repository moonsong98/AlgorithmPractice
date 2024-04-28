#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

const ll MOD=1000003;

matrix operator* (const matrix &A, const matrix &B) {
	matrix ret(sz(A), vector<ll>(sz(A[0]), 0));
	for(int i=0; i<sz(A); ++i)
		for(int j=0; j<sz(B[0]); ++j) {
			for(int k=0; k<sz(B); ++k)
				ret[i][j]+=A[i][k]*B[k][j];
			if(ret[i][j]>=MOD) ret[i][j]%=MOD;
		}
	return ret;
}

int main(void) {
	ll N, S, E, T;	
	cin >> N >> S >> E >> T;
	matrix M(5*N, vector<ll>(5*N, 0)), ans(5*N, vector<ll>(5*N, 0));
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j) {
			char ch; cin >> ch;
			int w=ch-'0';
			if(w>0) {
				M[i*5][j*5+w-1]=1;
				if(w>1)
					for(int k=w-1; k>=1; --k)
						M[j*5+k][j*5+k-1]=1;
			}
		}
	ans.assign(M.begin(), M.end());
	T--;
	while(T) {
		if(T%2) ans=M*ans;
		M=M*M;
		T>>=1;
	}
	cout << ans[(S-1)*5][(E-1)*5] << '\n';
}

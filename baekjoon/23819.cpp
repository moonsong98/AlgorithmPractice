#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

vector<vector<ll>> matrix;
vector<vector<ll>> m;
ll M;

ll mul(ll a, ll b) {
	return ((a%M) * (b%M))% M;
}

ll add (ll a, ll b) {
	return ((a%M) + (b%M))% M;
}


vector<vector<ll>> matMul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
	ll L=a.size(), N=b[0].size(), K=b.size();
	vector<vector<ll>> res(a.size(),vector<ll>(b[0].size(),0));	
	for(ll l=0; l<L; ++l) {
		for(ll n=0; n<N; ++n) {
			for(ll k=0; k<K; ++k) {
				res[l][n]=res[l][n]+a[l][k]*b[k][n]%M;
			}
			res[l][n]%=M;
		}
	}
	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, k;
	cin >> n >> k;
	vector<vector<ll>> seq(k,vector<ll>(1));
	for(ll i=k-1; i>=0; --i) cin >> seq[i][0];
	cin >> M;
	for(ll i=k-1; i>=0; --i) seq[i][0]%=M;
	matrix=vector<vector<ll>> (k, vector<ll>(k,0));
	m=vector<vector<ll>> (k, vector<ll>(k,0));
	for(ll i=0; i<k; ++i) matrix[i][i]=1;
	for(ll i=0; i<k; ++i) {
		if(i==0) for(ll j=0; j<k; ++j) m[i][j]=1;
		else m[i][i-1]=1;
	}
	int t=n-k;
	while(t) {
		if(t&1) matrix=matMul(matrix, m);
		m=matMul(m,m);
		t>>=1;
	}
	vector<vector<ll>> ans=matMul(matrix, seq);
	cout << ans[0][0] << '\n';
}
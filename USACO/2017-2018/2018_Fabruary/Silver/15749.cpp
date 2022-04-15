#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;

int main(void) {
	int N, B;
	cin >> N >> B;
	vector<int> f(N);
	vector<pii> b(B);
	vector<vector<bool>> cache(B, vector<bool>(N, false));
	for(auto &a: f) cin >> a;
	for(auto &p: b) cin >> p.fi >> p.se;
	cache[0][0]=true;
	for(int i=0; i<B; ++i) for(int j=0; j<N; ++j) {
		if(f[j]>b[i].fi) {
			cache[i][j]=false;
			continue;
		}	
		for(int k=0; k<i; ++k) 
			cache[i][j]=cache[i][j]||cache[k][j];
		for(int k=1; k<=b[i].se&&j-k>=0; ++k)
			cache[i][j] = cache[i][j]||cache[i][j-k];
	}
	for(int i=0; i<B; ++i) if(cache[i][N-1]) {
		cout << i << '\n';
		return 0;
	}
}
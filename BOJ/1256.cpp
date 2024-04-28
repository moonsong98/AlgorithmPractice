#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;
const int MAX=1e9;

int main(void) {
	int n, m, k, len; cin >> n >> m >> k; len=n+m;
	vector<vector<ll>> comb(len+1, vector<ll>(len+1,0));
	for(int i=0; i<=len; ++i) comb[i][0]=comb[i][i]=1;
	for(int i=0; i<=len; ++i) for(int j=1; j<i; ++j) {
		comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
		if(comb[i][j]>MAX) comb[i][j]=MAX;
	}
	
	if(comb[len][m] < k) {
		cout << -1 << '\n';
		return 0;
	}
	
	for(int i=0; i<len; ++i) {
		if(k <= comb[n+m-1][m]) {
			cout << 'a';
			--n;
		}
		else {
			cout << 'z';
			k-=comb[n+m-1][m];
			--m;
		}
	}
}
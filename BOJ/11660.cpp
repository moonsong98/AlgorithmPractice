#include<iostream>

using namespace std;

long long b[1025][1025];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) {
			cin>>b[i][j];
			b[i][j]+=(long long)b[i][j-1];
		}
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
		b[i][j]+=b[i-1][j];
	
	for(int i=0; i<m; ++i) {
		int p, q, r, s;
		cin >> p >> q >> r >> s;
		cout << b[r][s] -b[p-1][s]-b[r][q-1]+b[p-1][q-1]) << '\n';
	}
}
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int h, w;
		cin >> h >> w;
		vector<vector<int>> b(h, vector<int>(w));
		int y, x, M;
		for(int i=0; i<h; ++i) for(int j=0; j<w; ++j) {
			cin >> b[i][j];
			if(i==0&&j==0) {
				M=b[i][j];
				y=0, x=0;
			}
			else if(b[i][j]>M) {
				M=b[i][j];
				y=i; x=j;
			}
		}
		long long H=max(y+1, h-y);
		long long W=max(x+1, w-x);
		long long ans=H*W;
		cout << ans << '\n';
	}
}
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int h, w;
		cin >> h >> w;
		int y, x, M=-1e9-7;
		for(int i=0; i<h; ++i) for(int j=0; j<w; ++j) {
			int num; cin >> num;
			if(num>M) {
				y=i, x=j;
				M=num;
			}
		}
		long long H=max(y+1, h-y);
		long long W=max(x+1, w-x);
		long long ans=H*W;
		cout << ans << '\n';
	}
}

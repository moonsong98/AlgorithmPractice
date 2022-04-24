#include<bits/stdc++.h>
using namespace std;
 
int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		for(int &a: v) cin >> a;
		int cntInvalid=0;
		for(int i=-1; i<=1; ++i) {
			int a=v[0]+i;
			for(int j=1; j<n; ++j) {
				if(abs(v[j]-a-j)>1) {
					cntInvalid++;
					break;
				}
			}
		}
		if(cntInvalid<3) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
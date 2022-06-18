#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> s(n), e(n), d(n, 0);
		for(int &k:s) cin >> k;
		for(int &k:e) cin >> k;
		int cur=e[0];
		d[0]=e[0]-s[0];
		for(int i=1; i<n; ++i) {
			if(cur>=e[i]) continue;
			else if(cur>s[i]) d[i]=e[i]-cur;
			else d[i]=e[i]-s[i];
			cur=e[i];
		}
		for(int i=0; i<n; ++i) cout << d[i] << ' ' ;
		cout << '\n';
	}
}
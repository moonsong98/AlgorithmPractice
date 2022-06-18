#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		bool valid=true;
		int n, M=-1; cin >> n;
		vector<int> a(n), b(n), d(n);
		for(int &k: a) cin >> k;
		for(int &k: b) cin >> k;
		for(int i=0; i<n; ++i) {
			d[i]=a[i]-b[i];
			M=max(M, d[i]);
		}
		for(int i=0; i<n; ++i) {
			if(d[i]<0) valid=false;
			if(b[i]!=0 && d[i]<M) valid=false;
		}
		cout << (valid?"YES":"NO") << '\n';
	}
}
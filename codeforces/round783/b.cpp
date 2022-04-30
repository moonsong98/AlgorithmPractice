#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		long long n, m;
		cin >> n >> m;
		vector<long long> v(n);
		for(int i=0; i<n; ++i) cin >> v[i];
		sort(v.begin(), v.end(), [](long long a, long long b){return a>b;});
		long long ans=n;
		ans+=v[0]*2;
		for(int i=1; i+1<n; ++i) ans+=v[i];
		cout << (ans<=m?"YES":"NO") << '\n';
	}
}
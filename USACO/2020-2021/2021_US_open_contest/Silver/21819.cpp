#include<bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int N, K, L;
	cin >> N >> K >> L;
	vector<long long> v(N);
	for(long long& a: v) cin >> a;
	sort(v.begin(), v.end(), [](int a, int b){return a>b;});
	long long l=0, r=N, ans;
	while(l<=r) {
		long long h=l+(r-l)/2, n=0;
		for(int i=0; i<h; ++i) n+=max(0ll, h-v[i]);
		if(n<=(long long)K*L&&v[h-1]+K>=h) {
			ans=h;
			l=h+1;
		}
		else r=h-1;
	}
	cout << ans << '\n';
}
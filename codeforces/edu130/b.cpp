#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, q; cin >> n >> q;
	vector<long long> v(n);
	for(long long &num: v) cin >> num;
	sort(v.begin(), v.end(), greater<long long>());
	vector<long long> pSum(n+1, 0);
	for(int i=1; i<=n; ++i)
		pSum[i]=pSum[i-1]+v[i-1];
	while(q--) {
		int x, y; cin >> x >> y;
		cout << pSum[x]-pSum[x-y] << '\n';
	}
}